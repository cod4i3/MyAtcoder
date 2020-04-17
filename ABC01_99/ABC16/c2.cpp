#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define MAX_V 15
#define INF 1000
using namespace std;
using P = pair<int, int>;
// 計算量は O(|E|log|V|)
// firstが最短距離、 secondが頂点番号
struct edge {
  int to, cost;
};
int V;
vector<edge> G[MAX_V];
int d[MAX_V];

// 始点sから各頂点への最短距離
void dijkstra(int s) {
  // greater<P> を指定することで昇順（距離が小さい順)にする
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;

    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < V; i++) {
    if (d[i] == 2) ans++;
  }
  cout << ans << endl;
}

int main() {
  int N, M;
  cin >> N >> M;
  V = N;
  for (int i = 0; i < M; i++) {
    int n, m;
    cin >> n >> m;
    n--;
    m--;
    edge f = {m, 1}, t = {n, 1};
    G[n].emplace_back(f);
    G[m].emplace_back(t);
  }

  for (int i = 0; i < V; i++) {
    dijkstra(i);
  }
  return 0;
}