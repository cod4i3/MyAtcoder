#define _GLIBCXX_DEBUG
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
vector<vector<int>> color;
vector<vector<int>> G;
vector<vector<int>> used;
vector<bool> seen;
int K = 0;

void dfs(int v) {
  if (seen[v]) return;
  seen[v] = true;
  int c = 1;
  for (int i = 0; i < int(used[v].size()); i++) {
    if (c == used[v][i]) c++;
  }

  for (int nv : G[v]) {
    if (color[v][nv] != -1) continue;
    color[v][nv] = color[nv][v] = c;
    used[nv].emplace_back(c);
    dfs(nv);
    c++;
  }

  K = max(K, c - 1);
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;

  // グラフ入力受取
  G.resize(N);
  used.resize(N);
  seen.resize(N, false);
  // 探索
  color.resize(N, vector<int>(N, -1));
  vector<pair<int, int>> p(N);
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
    p[i] = {a, b};
  }

  dfs(0);
  cout << K << endl;
  for (int i = 0; i < N - 1; i++) {
    cout << color[p[i].first][p[i].second] << endl;
  }
  return 0;
}