#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
vector<int> G[100];
bool visited[100];
bool flag;

void dfs(int c, int p) {
  // 頂点から訪れられる点全て
  for (auto next : G[c]) {
    if (next == p) continue;
    if (visited[next]) {
      flag = false;
    } else {
      visited[next] = true;
      dfs(next, c);
    }
  }
}

int main() {
  cin >> n >> m;

  // 無向グラフの一つの形と覚えておく
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      flag = true;
      dfs(i, -1);
      if (flag) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
