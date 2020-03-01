#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> h(N + 1, 0);
  for (int i = 1; i <= N; i++) cin >> h[i];

  vector<int> dp(N + 1);
  dp[0] = dp[1] = 0;
  dp[2] = abs(h[2] - h[1]);
  for (int i = 3; i <= N; i++) {
    dp[i] =
        min(dp[i - 2] + abs(h[i - 2] - h[i]), dp[i - 1] + abs(h[i - 1] - h[i]));
  }
  cout << dp[N] << endl;
}