#include <algorithm>
#include <array>
#include <cstdio>
#include <queue>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
vector<bool> seen;
vector<int> ans(3000, 0);
int d[3000][3000];
vector<vector<int>> G(3000);

void bfs(int s) {
  queue<int> q;
  q.push(s);
  seen[s] = true;

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto next_v : G[v]) {
      if (seen[next_v]) continue;
      seen[next_v] = true;
      q.push(next_v);
      d[s][next_v] = d[s][v] + 1;
      if (s < next_v) ans[d[s][next_v]]++;
    }
  }
}

int main() {
  int N, X, Y;
  scanf("%d %d %d", &N, &X, &Y);
  X--;
  Y--;
  FOR(i, N - 1) {
    G[i].push_back(i + 1);
    G[i + 1].push_back(i);
  }
  G[X].push_back(Y);
  G[Y].push_back(X);
  FOR(i, N) FOR(j, N) d[i][j] = 0;

  FOR(i, N) {
    seen.assign(N, false);
    bfs(i);
  }

  for (int i = 1; i < N; i++) printf("%d\n", ans[i]);
  return 0;
}