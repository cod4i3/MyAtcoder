#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll INF = 1000000000;
const int MAX_V = 10;
using namespace std;
using P = pair<int, int>;

struct edge {
  ll to, cost;
};

int V;
vector<vector<edge>> G(MAX_V);
vector<vector<ll>> d(MAX_V, vector<ll>(MAX_V, INF));

// 始点sから各頂点への最短距離
void dijkstra(int s) {
  // greater<P> を指定することで昇順（距離が小さい順)にする
  priority_queue<P, vector<P>, greater<P>> que;

  d[s][s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[s][v] < p.first) continue;

    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[s][e.to] > d[s][v] + e.cost) {
        d[s][e.to] = d[s][v] + e.cost;
        que.push(P(d[s][e.to], e.to));
      }
    }
  }
}

int main() {
  int H, W;
  cin >> H >> W;
  REP(i, 10) REP(j, 10) {
    int c;
    cin >> c;
    edge e;
    e.to = j, e.cost = c;
    G[i].emplace_back(e);
  }

  vector<vector<int>> A(H, vector<int>(W));
  REP(i, H) REP(j, W) cin >> A[i][j];
  REP(i, 10) dijkstra(i);

  ll ans = 0;
  REP(i, H) REP(j, W) {
    int s = A[i][j];
    if (s == -1 || s == 1)
      continue;
    else
      ans += d[s][1];
  }

  cout << ans << endl;
  return 0;
}