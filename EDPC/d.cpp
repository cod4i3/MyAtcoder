#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N, W;
  cin >> N >> W;

  vector<ll> w(N), v(N);
  for (int i = 0; i < N; i++) {
    cin >> w[i] >> v[i];
  }

  // N番目まで選んで大きさWだったときの価値の総和の最大値
  vector<vector<ll>> dp(N + 10, vector<ll>(W + 100, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
      if (j + w[i] <= W)
        dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
    }
  }

  cout << dp[N][W] << endl;
  return 0;
}