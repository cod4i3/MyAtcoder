#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<ll> a(N, 0);
  for (int i = 0; i < N; i++) cin >> a[i];

  // dp[l][r] = l ~ r - 1（つまり区間[i, j)での X - Y
  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));

  for (int len = 1; len <= N; len++) {
    for (int l = 0; l + len <= N; l++) {
      // つまり len = r - l = 石の残り個数
      int r = l + len;

      // 奇数番
      if ((N - len) % 2 == 0) {
        // 左側を選んだ時、右側を選んだ時の X+Y の最大値
        dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r - 1]);
      } else {
        // 左側を選んだ時、右側を選んだ時の X-Y の最小値
        dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r - 1]);
      }
    }
  }

  cout << dp[0][N] << endl;
  return 0;
}