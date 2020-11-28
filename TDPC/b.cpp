#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;

  // Aからi個、Bからj個取った時から最後までの先手の最適スコア
  int a[A], b[B];
  for (int i = 0; i < A; i++) cin >> a[i];
  for (int i = 0; i < B; i++) cin >> b[i];

  // 最後の時点から考えるのが分かりやすい
  int dp[A + 1][B + 1];
  dp[A][B] = 0;
  for (int i = A; i >= 0; i--) {
    for (int j = B; j >= 0; j--) {
      if (i == A && j == B) continue;

      // 偶数個取ってる == 奇数 == 先手番
      if ((i + j) % 2 == 0) {
        if (i == A)
          dp[i][j] = dp[i][j + 1] + b[j];
        else if (j == B)
          dp[i][j] = dp[i + 1][j] + a[i];
        else
          dp[i][j] = max(dp[i][j + 1] + b[j], dp[i + 1][j] + a[i]);
      } else {
        if (i == A)
          dp[i][j] = dp[i][j + 1];
        else if (j == B)
          dp[i][j] = dp[i + 1][j];
        // 後手は最善を尽くす = より少ない先手のスコアが選ばれる
        else
          dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }
  cout << dp[0][0] << endl;
  return 0;
}
