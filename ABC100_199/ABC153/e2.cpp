#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll H, N;
  cin >> H >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

  vector<ll> dp(H + 1, 1e10);
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= H; j++) {
      if(j + A[i] <= H) dp[j + A[i]] = min(dp[j + A[i]], dp[j] + B[i]);
      else dp[H] = min(dp[H], dp[j] + B[i]);
    }
  }

  cout << dp[H] << endl;
  return 0;
}