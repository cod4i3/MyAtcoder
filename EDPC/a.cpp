#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> h(N + 1);
  for (int i = 1; i <= N; i++) cin >> h[i];

  vector<int> dp(N + 1);
  dp[0] = dp[1] = 0;
  dp[2] = abs(h[2] - h[1]);
  for (int i = 3; i <= N; i++) {
    int dif1 = abs(h[i] - h[i - 1]);
    int dif2 = abs(h[i] - h[i - 2]);
    dp[i] = min(dp[i - 1] + dif1, dp[i - 2] + dif2);
  }

  cout << dp[N] << endl;
}