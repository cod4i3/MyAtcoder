// 貰うDP
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> dp(N + 1);
  for (int i = 0; i <= N; i++) dp[i] = i;
  dp[0] = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j *= 6) {
      dp[i] = min(dp[i], dp[i - j] + 1);
    }
    for (int j = 1; j <= i; j *= 9) {
      dp[i] = min(dp[i], dp[i - j] + 1);
    }
  }

  cout << dp[N] << endl;
  return 0;
}