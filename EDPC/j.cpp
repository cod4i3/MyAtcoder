#include <iomanip>
#include <iostream>
#include <vector>
#define DOUBLE_DECIMAL_DIG 10
using namespace std;

int N;
// dp[i][j][k] = 1個の皿i個、2個の皿j個、3個の皿k個の時の期待値
vector<vector<vector<double>>> dp;

/*
  dp[i][j][k] = ( dp[i][j][k] * ((N - i - j - k)/N)
                + dp[i - 1][j][k] * (i / N)
                + dp[i + 1][j - 1][k] * (j / N)
                + dp[i][j + 1][k - 1] * (k / N) ) + 1

  イメージとしては分かれていく状態を一つに戻す感覚
                   dp[i][k][k]
               ↙︎   dp[i - 1][j][k]
  dp[i][j][k]  ←   dp[i][j - 1][k]
               ↖︎   dp[i][j][k - 1]

  dp[i][j][k]が両辺に出て、漸化式の無限ループとなるのでこれを式変形
  大学入試の確率問題でこういうのよくあるよね

  dp[i][j][k] = ( dp[i - 1][j][k] * (i / N)
                + dp[i + 1][j - 1][k] * (j / N)
                + dp[i][j + 1][k - 1] * (k * N)
                + 1) * (N / (i + j + k))
              = ( dp[i - 1][j][k] * i
                + dp[i + 1][j - 1][k] * j
                + dp[i][j + 1][k - 1] * k
                + N) * (1 / (i + j + k))
*/
double rec(int i, int j, int k) {
  if (dp[i][j][k] >= 0) return dp[i][j][k];
  if (i == 0 && j == 0 && k == 0) return 0.0;

  double res = 0.0;
  if (i > 0) res += rec(i - 1, j, k) * i;
  if (j > 0) res += rec(i + 1, j - 1, k) * j;
  if (k > 0) res += rec(i, j + 1, k - 1) * k;
  res += N;
  res *= 1.0 / double(i + j + k);

  return dp[i][j][k] = res;
}

int main() {
  cin >> N;

  int one = 0, two = 0, three = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a == 1) one++;
    if (a == 2) two++;
    if (a == 3) three++;
  }

  dp.resize(N + 10,
            vector<vector<double>>(N + 10, vector<double>(N + 10, -1)));

  cout << fixed << setprecision(12) << rec(one, two, three) << endl;
}