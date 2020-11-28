#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int n = s.length(), m = t.length();

  // dp[i][j] = sのi + 1文字目、tのj + 1文字まででのLCS
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i] == t[j])
        dp[i + 1][j + 1] = dp[i][j] + 1;
      else
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    }
  }


  string ans = "";
  int i = n, j = m;

  // i行j列の表を考える、要は左上に遡っていけばいい
  // dpの性質として等しいところになると右下に移動、右と下の移動は単なるコピーのため
  while (i && j) {
      if(dp[i][j] == dp[i - 1][j]) i--; //上に遡る
      else if(dp[i][j] == dp[i][j - 1]) j--; //左に遡る
      else{
          ans = s[i - 1] + ans; // 一番前に付け足す
          i--, j--; // 左上に遡る
      }
  }

  cout << ans << endl;
  return 0;
}