#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MAX_V = 55;
const ll INF = 10000000000;

// 各都市ごとの最短路の直前の頂点
vector<ll> pre(MAX_V);
vector<vector<pair<ll, ll>>> cost(MAX_V, vector<pair<ll, ll>>(MAX_V));
vector<ll> d(MAX_V);
vector<ll> money(MAX_V);
vector<bool> used(MAX_V);
// 頂点数
ll V;

// 都市1からの距離を求める
void dijkstra(int s) {
  d.assign(V, INF);
  used.assign(V, false);
  pre.assign(V, -1);
  d[s] = 0;
  money[s] = 0;

  while (true) {
    int v = -1;
    for (int u = 0; u < V; u++) {
      if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
    }

    if (v == -1) break;
    used[v] = true;

    for (int u = 0; u < V; u++) {
      if (d[u] > d[v] + cost[v][u].second) {
        money[u] = money[v] + cost[v][u].first;
        d[u] = d[v] + cost[v][u].second;
        pre[u] = v;
      }
    }
  }
}

int main() {
  ll N, M, S;
  cin >> N >> M >> S;
  V = N;
  vector<vector<int>> graph(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    ll a, b;
    cin >> u >> v >> a >> b;
    u--;
    v--;
    cost[u][v] = make_pair(a, b);
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }

  vector<pair<ll, ll>> change(N);
  for (int i = 0; i < N; i++) {
    ll c, d;
    cin >> c >> d;
    change[i] = make_pair(c, d);
  }
}