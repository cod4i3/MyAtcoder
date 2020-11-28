// グリッドDP
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> a(H);
  for (int i = 0; i < H; i++) cin >> a[i];

  // dp[i - 1][j - 1] = (i, j)までの経路、0-indexなので1引く
  // 引かない場合はdp[1][1] = 1
  vector<vector<ll>> dp(H + 1, vector<ll>(W + 1, 0));

  dp[0][0] = 1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      dp[i][j] %= MOD;
      if (i + 1 < H && a[i + 1][j] != '#') dp[i + 1][j] += dp[i][j];
      if (j + 1 < W && a[i][j + 1] != '#') dp[i][j + 1] += dp[i][j];
    }
  }

  cout << dp[H - 1][W - 1] << endl;
  return 0;
}