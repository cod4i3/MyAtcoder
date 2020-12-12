// 配るDP
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> dp(N + 1, 1e6);
  dp[0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 1; i + j <= N; j *= 6) {
      dp[i + j] = min(dp[i + j], dp[i] + 1);
    }
    for (int j = 1; i + j <= N; j *= 9) {
      dp[i + j] = min(dp[i + j], dp[i] + 1);
    }
  }

  cout << dp[N] << endl;
  return 0;
}