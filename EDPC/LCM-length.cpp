#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int n = s.length(), m = t.length();

  // dp[i][j] = sのi文字目、tのj文字まででのLCS
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i] == t[j])
        dp[i + 1][j + 1] = dp[i][j] + 1;
      else
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    }
  }


  cout << dp[n][m] << endl;
  return 0;
}