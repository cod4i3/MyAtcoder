#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_M 300000
using Graph = vector<vector<int> >;
int N, M;
bool flag = false;

vector<bool> seen;
void dfs(const Graph &G, int v, int cnt) {
  if (cnt >= 2) return;
  seen[v] = true;
  for (auto next_v : G[v]) {
    if (next_v == N) flag = true;
    if (seen[next_v]) continue;
    dfs(G, next_v, cnt + 1);
  }
}

int main() {
  cin >> N >> M;
  Graph G(MAX_M);

  REP(i, M) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  seen.assign(M, false);
  dfs(G, 1, 0);
  if (flag)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;

  return 0;
}