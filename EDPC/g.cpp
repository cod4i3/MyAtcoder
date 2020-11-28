// トポロジカルソートの解法
// g2のメモ化再帰の方が簡単かも
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(N);  // グラフ
  vector<int> deg(N, 0);     // 入次数
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].emplace_back(y);
    deg[y]++;
  }

  queue<int> que;
  for (int i = 0; i < N; i++)
    if (deg[i] == 0) que.push(i);

  // dp[v] = 頂点vまでのグラフの最長距離
  vector<int> dp(N, 0);

  // トポロジカルソートされたグラフが欲しい時
  // vector<int> tp_sorted;

  // 入次数を引いて行って0になったらキューに入れる
  // これによって入次数の小さい順から辿れるうえ、距離も求められる
  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (int nv : G[v]) {
      deg[nv]--;
      if (deg[nv] == 0) {
        que.push(nv);
        dp[nv] = max(dp[nv], dp[v] + 1);
      }
    }

    // tp_sorted.emplace_back(v);
  }

  int ans = 0;
  for(int i=0; i<N; i++) ans = max(ans, dp[i]);
  cout  << ans << endl;
  return 0;
}