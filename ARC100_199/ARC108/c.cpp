#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int to;      // 辺の行き先
  int weight;  // 辺の重み
  Edge(int t, int w) : to(t), weight(w) {}
};

int N, M;
vector<vector<Edge>> G;
vector<int> label;
void dfs(int v, int l, bool same) {
  // v から行ける各頂点 next_v について
  if(label[v]) return;
  label[v] = l;
  for (int i = 0; i < G[v].size(); i++) {
    if(label[G[v][i].to]) continue;
    if (same) {
      dfs(G[v][i].to, l % N + 1, false);
    } else {
      dfs(G[v][i].to, l, true);
    }
  }
  return;
}

int main() {
  cin >> N >> M;

  G.resize(N);
  label.resize(N, 0);
  for (int i = 0; i < M; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    from--, to--;
    G[from].push_back(Edge(to, weight));
  }

  dfs(0, G[0][0].weight, true);
  for (int i = 0; i < N; i++) {
    cout << label[i] << endl;
  }
  return 0;
}