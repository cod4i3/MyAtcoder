#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> G;
vector<bool> seen;

void dfs(int cur) {
  if (seen[cur]) return;
  seen[cur] = true;
  for (int n : G[cur]) {
    dfs(n);
  }
}

int main() {
  int N, M;
  cin >> N >> M;

  seen.resize(N, false);
  G.resize(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a -= 1, b -= 1;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (seen[i]) continue;
    dfs(i);
    ans += 1;
  }

  cout << ans - 1 << endl;
  return 0;
}