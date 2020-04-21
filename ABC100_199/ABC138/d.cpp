#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define MAX_N 250000
bool seen[MAX_N];
ll cost[MAX_N];

void dfs(int cur, const vector<vector<int>> &G) {
  seen[cur] = true;
  for (int x : G[cur]) {
    if (seen[x]) continue;
    cost[x] += cost[cur];
    dfs(x, G);
  }
  return;
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> G(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  for (int i = 0; i < Q; i++) {
    int p, x;
    cin >> p >> x;
    cost[p - 1] += x;
  }

  dfs(0, G);
  for (int i = 0; i < N - 1; i++) {
    cout << cost[i] << " ";
  }
  cout << cost[N - 1] << endl;

  return 0;
}