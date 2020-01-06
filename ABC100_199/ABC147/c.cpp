#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
using Graph = vector<vector<pair<int, bool> > >;

// 二部グラフ判定
vector<int> color;
bool dfs(const Graph &G, int v, int cur) {
  color[v] = cur;
  for (auto next_v : G[v]) {
    // 隣接頂点がすでに色確定していた場合
    if (color[next_v.first] != -1) {
      if (color[next_v.first] != next_v.second) return false;
      continue;
    }

    // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
    if (!dfs(G, next_v.first, next_v.second)) return false;
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  Graph G(N);
  for (int i = 1; i <= N + 1; i++) {
    int A;
    cin >> A;
    for (int j = 0; j < A; j++) {
      int x;
      bool y;
      cin >> x >> y;
      G[i].push_back(make_pair(x - 1, y));
    }
  }

  color.assign(N + 1, -1);
  int cnt, ans = 0;
  for (int v = 0; v < N; ++v) {
    cnt = 0;
    if (color[v] != -1) continue;  // v が探索済みだったらスルー
    if (!dfs(G, v, 1))
      for (auto c : color)
        if (c == 1) cnt++;
    ans = max(cnt, ans);
  }

  cout << ans << endl;
  return 0;
}