#include <cstring>
#include <iostream>
#include <vector>
#include<iomanip>
#define DECIMAL_DIG 23
using namespace std;
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  // dp[i][j][k] = 袋の枚数がi, j, kであるときの期待値
  vector<vector<vector<double>>> dp(
      110, vector<vector<double>>(110, vector<double>(110, 0)));

  for (int a = 99; a >= A; a--) {
    for (int b = 99; b >= B; b--) {
      for (int c = 99; c >= C; c--) {
        dp[a][b][c] += (double(a) / double(a + b + c)) * (dp[a + 1][b][c] + 1);
        dp[a][b][c] += (double(b) / double(a + b + c)) * (dp[a][b + 1][c] + 1);
        dp[a][b][c] += (double(c) / double(a + b + c)) * (dp[a][b][c + 1] + 1);
      }
    }
  }
  cout << fixed << setprecision(10) << dp[A][B][C] << endl;
  return 0;
}