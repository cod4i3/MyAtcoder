#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int>> G;
vector<int> dist;
vector<bool> seen;
int res = 0;

int dist_init(int v) {
  if (seen[v]) return 0;
  seen[v] = true;

  for (auto nv : G[v]) {
    if (seen[nv]) continue;
    if (dist_init(nv) > 0) dist[v] = dist[nv] + 1;
  }

  if (v == N - 1) dist[v] = 1;
  return dist[v];
}

void dfs(int v) {
  if (seen[v]) return;
  if (dist[v] == -1) return;
  seen[v] = true;
  for (auto nv : G[v]) {
    if (seen[nv]) continue;
    dfs(nv);
  }
  res++;
  return;
}

int main() {
  cin >> N;

  G.resize(N);
  dist.resize(N, 0);
  seen.resize(N, false);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  dist_init(0);
  for (int i = 0; i < N; i++) {
    if (dist[i] && dist[0] / 2 >= dist[i]) dist[i] = -1;
  }
  dist[N - 1] = -1;


  for(int i=0; i<N; i++) seen[i] = false;
  dfs(0);

  if (res > (N - res))
    cout << "Fennec" << endl;
  else
    cout << "Snuke" << endl;
  return 0;
}