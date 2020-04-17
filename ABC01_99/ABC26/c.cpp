#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 30
using ll = long long;

ll max(ll a, ll b) {
  if (a > b)
    return a;
  else
    return b;
}

ll min(ll a, ll b) {
  if (a > b)
    return b;
  else
    return a;
}

int cost[MAX_N];
bool seen[MAX_N];
void dfs(int n, const vector<vector<int>> &B) {
  seen[n] = true;
  if (!B[n].size()) {
    cost[n] = 1;
    return;
  }

  ll max_c = 1, min_c = 100000000;
  for (auto x : B[n]) {
    if (seen[x])
      continue;
    else
      dfs(x, B);
    max_c = max(max_c, cost[x]);
    min_c = min(min_c, cost[x]);
  }

  cost[n] = max_c + min_c + 1;
  return;
}

int main() {
  int N;
  cin >> N;
  vector<vector<int>> B(N);
  // 部下を保存する
  for (int i = 0; i < N - 1; i++) {
    int b;
    cin >> b;
    b--;
    B[b].emplace_back(i + 1);
  }

  ll ans = 0;
  dfs(0, B);

  cout << cost[0] << endl;
  return 0;
}
