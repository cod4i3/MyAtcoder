#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N, W;
  cin >> N >> W;

  vector<ll> w(N), v(N);
  for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

  // dp[i][j] = i個選び価値がjだったときの重さの総和
  vector<vector<ll>> dp(N + 10, vector<ll>(N * 1100, 1e10));
  dp[0][0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= N * 1000; j++) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      if (j + v[i] <= N * 1000) {
        dp[i + 1][j + v[i]] = min(dp[i][j] + w[i], dp[i + 1][j + v[i]]);
      }
    }
  }

  ll ans = 0;
  for (int j = 0; j <= N * 1000; j++) {
    if (dp[N][j] <= W) ans = j;
  }
  cout << ans << endl;
  return 0;
  return 0;
}