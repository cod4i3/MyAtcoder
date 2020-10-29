#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MAX_N = 1e5 + 10;

struct Edge {
  ll to;      // 辺の行き先
  ll weight;  // 辺の重み
  Edge(ll t, ll w) : to(t), weight(w) {}
};

using Graph = vector<vector<Edge> >;
bool seen[MAX_N];
bool color[MAX_N];
Graph G;

void dfs(int cur) {
  if (seen[cur]) return;
  seen[cur] = true;
  for (auto next : G[cur]) {
    if (next.weight % 2 == 0)
      color[next.to] = color[cur];
    else
      color[next.to] = color[cur] ^ 1;
    dfs(next.to);
  }
  return;
}

int main() {
  int N;
  cin >> N;

  G.resize(N);
  for (int i = 0; i < N - 1; i++) {
    ll from, to, weight;
    cin >> from >> to >> weight;
    from--;
    to--;
    G[from].emplace_back(Edge(to, weight));
    G[to].emplace_back(Edge(from, weight));
  }

  for (int i = 0; i < N; i++) {
    seen[i] = false;
    color[i] = 0;
  }

  for(int i=0; i<N; i++) dfs(i);
  for (int i = 0; i < N; i++) {
    cout << color[i] << endl;
  }

  return 0;
}