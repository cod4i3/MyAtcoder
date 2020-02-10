#include <algorithm>
#include <iostream>
using namespace std;
#define MAX_N 100000

int main() {
  int N;
  cin >> N;

  int cnt = 0;
  int dp[MAX_N];
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 1; i <= N; i++) {
    if (i <= 5)
      dp[i] = dp[i - 1] + 1;
    else if (i <= 8)
      dp[i] = dp[i - 6] + 1;
    else if (i <= 9)
      dp[i] = dp[i - 9] + 1;
    else {
      int six = 6, nine = 9;
      while (i > six) six *= 6;
      while (i > nine) nine *= 9;
      if (i % six != 0) six /= 6;
      if (i % nine != 0) nine /= 9;
      dp[i] = min(dp[i - 1], min(dp[i - six], dp[i - nine])) + 1;
    }
  }

  cout << dp[N] << endl;
  return 0;
}