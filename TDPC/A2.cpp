#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int p[N];
  for (int i = 0; i < N; i++) cin >> p[i];

  // dp[i][j] = i問解いた時の合計点がj
  vector<vector<bool>> dp(N + 10, vector<bool>(N * 110, false));
  dp[0][0] = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= N * 100; j++) {
      if(j < p[i]) dp[i + 1][j] = dp[i][j];
      else dp[i + 1][j] = dp[i][j - p[i]] || dp[i][j];
    }
  }

  int ans = 0;
  for(int i=0; i<=N*100; i++) if(dp[N][i]) ans++;
  cout << ans << endl;
  return 0;
}