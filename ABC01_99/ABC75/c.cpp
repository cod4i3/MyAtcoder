#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define m0(x) memset(x, 0, sizeof(x))
#define MAX_N 55
using namespace std;
using Graph = vector<vector<int> >;
int N, M;
Graph G(MAX_N);
vector<bool> seen;
vector<int> a(MAX_N), b(MAX_N);

void dfs(const Graph &G, int v) {
  seen[v] = true;
  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;
    dfs(G, next_v);
  }
}

int main() {
  cin >> N >> M;
  REP(i, M) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int ans = 0;

  for (int i = 1; i < N; i++) {
    seen.assign(N, false);
    dfs(G, i);
    REP(j, seen.size()) cout << seen[j] << ' ';
    cout << endl;
    for (int j = 1; j < seen.size(); j++) {
      if (!seen[j]) {
        ans++;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}