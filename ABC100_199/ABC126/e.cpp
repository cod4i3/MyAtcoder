#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 1e5 + 9;

bool seen[MAX_N];
vector<vector<int>> G;

void dfs(int cur) {
  if (seen[cur]) return;
  seen[cur] = true;
  for (auto next : G[cur]) {
    dfs(next);
  }
  return;
}

int main() {
  int N, M;
  cin >> N >> M;
  G.resize(N);
  for (int i = 0; i < M; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x -= 1, y -= 1;
    G[x].emplace_back(y);
    G[y].emplace_back(x);
  }

  for(int i=0; i<N; i++) seen[i] = false;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if(G[i].size() == 0){
      ans += 1;
      continue;
    }
    if (seen[i]) continue;
    dfs(i);
    ans += 1;
  }

  cout << ans << endl;
  return 0;
}