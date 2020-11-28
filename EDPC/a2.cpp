#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  ll dp[N + 1], h[N + 1];
  dp[0] = dp[1] = 0;

  for (int i = 1; i <= N; i++) cin >> h[i];
  dp[2] = abs(h[1] - h[2]);
  for (int i = 3; i <= N; i++) {
    dp[i] =
        min(dp[i - 2] + abs(h[i] - h[i - 2]), dp[i - 1] + abs(h[i] - h[i - 1]));
  }
  cout << dp[N] << endl;
  return 0;
}