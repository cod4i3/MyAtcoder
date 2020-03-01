#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N + 1), b(N + 1), c(N + 1);
  vector<vector<int> > dp(N + 1, vector<int>(3));
  for (int i = 1; i <= N; i++) cin >> a[i] >> b[i] >> c[i];
  dp[1][0] = a[1], dp[1][1] = b[1], dp[1][2] = c[1];
  for (int i = 2; i <= N; i++) {
    dp[i][0] = max(dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]);
    dp[i][1] = max(dp[i - 1][0] + b[i], dp[i - 1][2] + b[i]);
    dp[i][2] = max(dp[i - 1][0] + c[i], dp[i - 1][1] + c[i]);
  }

  cout << max({dp[N][0], dp[N][1], dp[N][2]}) << endl;
  return 0;
}