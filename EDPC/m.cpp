#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;

  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];

  // dp[i][j] = i番目までの子供にj個の飴を配る場合の数
  vector<vector<ll>> dp(N + 10, vector<ll>(K + 10, 0));
  // cum[i] = その時点で 0 ~ i 個使う場合の数の累積和
  vector<ll> cum(K + 10, 0);
  /*
     普通にdpを行うと
     rep(i, N)rep(j, K + 1){
         rep(k, a[i] + 1){
             if(j - k >= 0){
                 dp[i + 1][j + 1] += dp[i][j - k];
                 dp[i + 1][j + 1] %= MOD;
             }
         }
     }

     これだと計算量が膨大すぎるので累積和を使う
  */

  for (int i = 0; i <= N; i++) dp[i][0] = 1;

  for (int i = 0; i < N; i++) {
    cum[0] = dp[i][0];
    // cum[j - 1] = dp[i - 1][0] + do[i - 1][1] + dp[i - 1][j - 2]
    // cum[j]     = dp[i - 1][0] + dp[i - 1][1] + … + dp[i - 1][j - 1]
    //            = cum[j - 1] + dp[i - 1][j - 1]
    for (int j = 1; j <= K + 1; j++) {
      cum[j] = (dp[i][j] + cum[j - 1]);
    }
    // k = 0 ~ j - a[i]
    // dp[i][j] = dp[i - 1][0] + dp[i - 1][1] + … + dp[i - 1][k]
    // 上の式より cum[j + 1] - cum[j] = dp[i][j]
    for (int j = 1; j <= K + 1; j++) {
      if (j - a[i] <= 0) {
        dp[i + 1][j] = cum[j] % MOD;
      } else {
        dp[i + 1][j] = (cum[j] - cum[j - a[i] - 1]) % MOD;
      }
    }
  }

  cout << dp[N][K] << endl;
  return 0;
}