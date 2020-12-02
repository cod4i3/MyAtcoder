#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll solve(string str) {
  vector<int> dig;
  for (auto s : str) dig.emplace_back(s - '0');
  int l = dig.size();

  // dp[i][smaller][flag]
  // i桁目まで、小さいかどうかのflag、4または9を含んでいるかどうかのflag
  // 0桁目は数字"X"を"0X"として考えたときの0
  vector<vector<vector<ll>>> dp(20, vector<vector<ll>>(2, vector<ll>(2, 0)));
  dp[0][0][0] = 1;

  for (int i = 0; i < l; i++) {
    for (int smaller = 0; smaller < 2; smaller++) {
      for (int flag = 0; flag < 2; flag++) {
        // smallerが成立するなら9まで、じゃないならその桁の数まで
        for (int x = 0; x <= (smaller ? 9 : dig[i]); x++) {
          dp[i + 1][smaller || x < dig[i]][flag || x == 4 || x == 9] +=
              dp[i][smaller][flag];
        }
      }
    }
  }

  return dp[l][0][1] + dp[l][1][1];
}

int main() {
  string A, B;
  cin >> A >> B;
  A = to_string(stoll(A) - 1);

  cout << solve(B) - solve(A) << endl;
  return 0;
}