#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define m0(x) memset(x, 0, sizeof(x))
#define MAX_N 55
using namespace std;
int N, M;
vector<bool> seen;
bool visited[55][55];

void dfs(const vector<vector<bool> > &v, int i) {
  seen[i] = true;
  for (int j = 0; j < N; j++) {
    if (!v[i][j]) continue;
    if (seen[j]) continue;
    dfs(v, j);
  }
}

int main() {
  cin >> N >> M;
  vector<vector<bool> > edge(N + 1, vector<bool>(N + 1, 0));
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a][b] = true;
    edge[b][a] = true;
  }

  int ans = 0;
  REP(i, N) {
    REP(j, N) {
      seen.assign(N, false);
      if (!edge[i][j]) continue;
      if (visited[i][j] || visited[j][i]) continue;
      edge[i][j] = edge[j][i] = false;
      dfs(edge, i);
      edge[i][j] = edge[j][i] = true;

      int cnt = 0;
      REP(k, N) if (seen[k]) cnt++;
      if (cnt != N) ans += 1;

      visited[i][j] = visited[j][i] = true;
    }
  }

  cout << ans << endl;
}