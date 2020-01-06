#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int> >;
typedef long long ll;

vector<bool> seen;
void dfs(vector<pair<int, int> > plots, int v, double dis) {
  seen[v] = true;
  for (auto next_v : plots[v]) {
    if (seen[next_v]) continue;
    dis += plots[next_v]
    dfs(G, next_v, dis);
  }
}

int main() {
  int N;
  cin >> N;

  vector<pair<int, int> > plots(N);
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    pair<int, int> plot = make_pair(x, y);
    plots[i] = plot;
  }

  seen.assign(N, false);
  dfs(plots, 0, 0);
}