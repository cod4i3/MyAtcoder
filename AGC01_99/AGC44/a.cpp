#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll N, A, B, C, D;
ll sum = 0;
ll seen[200][200][200][200];

ll dfs(ll i, ll j, ll k, ll l, ll cur) {
  if (seen[i][j][k][l]) return seen[i][j][k][l];
  seen[i][j][k][l] = A * i + B * j + C * k + D * l + abs(cur - N) * D;
  if (cur >= N) return A * i + B * j + C * k + D * l + abs(cur - N) * D;

  // if (cur == 0) return (1LL << 60);
  if (i >= 60) return A * i + B * j + C * k + D * l + abs(cur - N) * D;
  if (j >= 40) return A * i + B * j + C * k + D * l + abs(cur - N) * D;
  if (k >= 30) return A * i + B * j + C * k + D * l + abs(cur - N) * D;
  if (l >= 150) return A * i + B * j + C * k + D * l + abs(cur - N) * D;

  sum = min({dfs(i + 1, j, k, l, cur * 2), dfs(i, j + 1, k, l, cur * 3),
             dfs(i, j, k + 1, l, cur * 5), dfs(i, j, k, l + 1, cur + 1)});
  return A * i + B * j + C * k + D * l + abs(cur - N) * D;
}

int main() {
  ll T;
  cin >> T;
  vector<ll> ans;
  for (ll t = 0; t < T; t++) {
    cin >> N >> A >> B >> C >> D;
    sum = (1LL << 60);
    dfs(0, 0, 0, 1, 1);
    ans.emplace_back(sum);
  }

  for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  return 0;
}