#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> h(N + 1, 0);
  for (int i = 1; i <= N; i++) cin >> h[i];

  vector<ll> dp(N + 10, 1e10);
  dp[0] = dp[1] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      if (i + j > N) break;
      dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
    }
  }

  cout << dp[N] << endl;
  return 0;
}