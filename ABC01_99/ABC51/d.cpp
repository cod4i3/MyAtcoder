#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int> >;

struct Edge {
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};

int main() {
  int N, M;
  M = min(N * (N - 1) / 2, 1000);
  cin >> N >> M;
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}