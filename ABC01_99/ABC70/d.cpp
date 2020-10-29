#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct edge {
  ll to, cost;
  edge(ll t, ll c) : to(t), cost(c) {}
};
const ll MAX_V = 1e5 + 7;
const ll INF = 1e16;

int N;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + N, INF);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    ll v = p.second;
    if (d[v] < p.first) continue;

    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main() {
  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a -= 1, b -= 1;
    G[a].emplace_back(edge(b, c));
    G[b].emplace_back(edge(a, c));
  }

  dijkstra(0);
}