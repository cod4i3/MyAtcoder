#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll sum = 0, res = 0;
vector<bool> seen;
vector<ll> a, b;

void dfs(const vector<vector<int>> &G, int v) {
  if(seen[v]) return;
  seen[v] = true;
  sum += a[v];
  res += b[v];
  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;
    dfs(G, next_v);
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  a.resize(N), b.resize(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < N; i++) cin >> b[i];
  seen.resize(N, false);

  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    int c, d;
    cin >> c >> d;
    c -= 1, d -= 1;
    G[c].emplace_back(d);
    G[d].emplace_back(c);
  }

  for (int i = 0; i < N; i++) {
    dfs(G, i);
    if (sum != res) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}