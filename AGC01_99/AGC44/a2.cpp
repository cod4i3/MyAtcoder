#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll T;
  cin >> T;

  vector<ll> ans;
  ll dp[100][100][100][100];
  dp[0][0][0][1] = 1;
  for (int t = 0; t < T; t++) {
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    ll sum = (1LL << 60);
    for (int i = 0; i <= 60; i++) {
      for (int j = 0; j < 40; j++) {
        for (int k = 0; k < 30; k++) {
          for (int l = 0; l < 100; l++) {
            dp[i + 1][j][k][l] = dp[i][j][k][l] * 2;
            dp[i][j + 1][k][l] = dp[i][j][k][l] * 3;
            dp[i][j][k + 1][l] = dp[i][j][k][l] * 5;
            dp[i][j][k][l + 1] = dp[i][j][k][l] + 1;
            if (dp[i][j][k][l] >= N) {
              sum = min(sum, A * i + B * j + C * k + D * l +
                                 (abs(dp[i][j][k][l] - N) * D));
            }
          }
        }
      }
    }
    ans.emplace_back(sum);
  }

  for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  return 0;
}