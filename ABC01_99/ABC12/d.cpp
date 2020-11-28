#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct Edge {
  int to, weight;
  Edge(int t, int w) : to(t), weight(w) {}
};

int N, M;
vector<vector<Edge>> G;
vector<vector<ll>> dist;
vector<bool> seen;

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P>> que;
  dist[s][s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (dist[s][v] < p.first) continue;

    for (int i = 0; i < G[v].size(); i++) {
      Edge e = G[v][i];
      if (dist[s][e.to] > dist[s][v] + e.weight) {
        dist[s][e.to] = dist[s][v] + e.weight;
        que.push(P(dist[s][e.to], e.to));
      }
    }
  }
}

int main() {
  cin >> N >> M;
  G.resize(N);
  seen.resize(N, false);
  dist.resize(N);
  for (int i = 0; i < N; i++) dist[i].resize(N, N * 1000 + 10);
  for (int i = 0; i < N; i++) dist[i][i] = 0;


  for (int i = 0; i < M; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    from--, to--;
    G[from].emplace_back(Edge(to, weight));
    G[to].emplace_back(Edge(from, weight));
  }

  for (int i = 0; i < N; i++) {
    dijkstra(i);
  }


  ll ans = 10000000;
  for (int i = 0; i < N; i++) {
    ll res = 0;
    for (int j = 0; j < N; j++) {
      res = max(res, dist[i][j]);
    }
    ans = min(res, ans);
  }

  cout << ans << endl;
  return 0;
}