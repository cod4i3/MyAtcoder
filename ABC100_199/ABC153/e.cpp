#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll H, N;
  cin >> H >> N;
  vector<ll> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

  // dp[i][j] = i番目までの魔法でjダメージにするまでの魔力の最小値
  vector<vector<ll>> dp(N + 1, vector<ll>(H + 1, 1e10));
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (ll j = 0; j <= H; j++) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      dp[i + 1][min(H, j + A[i])] =
          min(dp[i + 1][min(H, j + A[i])], dp[i + 1][j] + B[i]);
    }
  }


  cout << dp[N][H] << endl;
  return 0;
}