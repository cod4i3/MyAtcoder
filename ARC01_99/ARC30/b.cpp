#include <iostream>
#include <vector>
using namespace std;

vector<bool> seen;
vector<vector<int>> G;
vector<int> h;
int dfs(int v) {
  if (seen[v]) return 0;
  seen[v] = true;

  int ans = 0, res = 0;
  for (int nv : G[v]) {
      ans += dfs(nv);
  }

  if(ans == 0){
      if(h[v]) return 2;
      else return 0;
  }
  return ans + 2;
}

int main() {
  int N, x;
  cin >> N >> x;
  x--;

  h.resize(N);
  for (int i = 0; i < N; i++) cin >> h[i];

  G.resize(N, vector<int>());
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  seen.resize(N, false);

  cout << max(dfs(x) - 2, 0) << endl;
  return 0;
}