#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int to, weight;
  Edge(int t, int w) : to(t), weight(w) {}
};

vector<vector<int>> dist;
vector<int> res;

void bfs(int from, vector<vector<Edge>> G, vector<vector<bool>> seen) {
  queue<int> que;
  que.push(from);

  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto next_v : G[v]) {
      int to = next_v.to, weight = next_v.weight;
      if (seen[from][to]) continue;
      que.push(to);
      seen[from][to] = seen[to][from] = true;

      dist[from][to] = min(dist[from][to], dist[from][v] + weight);
      res[from] = max(res[from], dist[from][to]);
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<Edge>> G(N);

  vector<vector<bool>> seen(N, vector<bool>(N, false));
  dist.resize(N);
  for (int i = 0; i < N; i++) dist[i].resize(N, 100000000);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) dist[i][j] = 0;
  res.resize(N, -1);

  for (int i = 0; i < M; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    from--, to--;
    G[from].emplace_back(Edge(to, weight));
    G[to].emplace_back(Edge(from, weight));
  }

  for (int i = 0; i < N; i++) {
    bfs(i, G, seen);
  }

  int ans = 100000000;
  for (int i = 0; i < N; i++) ans = min(ans, res[i]);

  cout << ans << endl;
  return 0;
}