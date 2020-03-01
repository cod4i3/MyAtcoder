#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> h(N + 1, 0);
  for (int i = 1; i <= N; i++) cin >> h[i];

  vector<int> dp(N + 1, 1000000000);
  dp[0] = dp[1] = 0;
  dp[2] = abs(h[2] - h[1]);
  for (int i = 3; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      if (i - j == 0) break;
      dp[i] = min(dp[i], dp[i - j] + abs(h[i - j] - h[i]));
    }
  }
  cout << dp[N] << endl;
}