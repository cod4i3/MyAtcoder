#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define MAX_N 100007
struct Edge {
  ll to;      // 辺の行き先
  ll weight;  // 辺の重み
  Edge(ll t, ll w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge> >;
bool seen[MAX_N];

int main() {
  int N;
  cin >> N;

  Graph G(N);
  for (int i = 0; i < N; ++i) {
    ll from, to, weight;
    cin >> from >> to >> weight;
    from--;
    to--;
    G[from].push_back(Edge(to, weight));
  }

  for (int i = 0; i < N; i++) {
    if (seen[i] == 1) continue;
    seen[i] = 0;
    if (G[i].empty()) continue;
    for (int j = 0; j < G[i].size(); j++) {
      Edge cur = G[i][j];
      if (cur.weight % 2 == 0)
        seen[cur.to] = seen[i];
      else
        seen[cur.to] = seen[i] ^ 1;
    }
  }

  for (int i = 0; i < N; i++) {
    cout << seen[i] << endl;
  }
  return 0;
}