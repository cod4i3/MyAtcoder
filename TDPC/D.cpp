#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  int N;
  ll D;
  cin >> N >> D;

  // それぞれの素因数(2,3,5)で何回割り切れたか
  int A = 0, B = 0, C = 0;
  while (D % 2 == 0) A++, D /= 2;
  while (D % 3 == 0) B++, D /= 3;
  while (D % 5 == 0) C++, D /= 5;

  // 2,3,5以外の素因数が入ってる場合絶対にその値にならない
  if (D > 1) {
    cout << 0 << endl;
    return 0;
  }

  double dp[N + 1][A + 1][B + 1][C + 1];
  memset(dp, 0, sizeof(dp));
  dp[0][0][0][0] = 1.0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= A; j++) {
      for (int k = 0; k <= B; k++) {
        for (int l = 0; l <= C; l++) {
          double tmp = (1.0 / 6.0) * dp[i][j][k][l];
          // 1~6の確率
          dp[i + 1][j][k][l] += tmp;
          dp[i + 1][min(j + 1, A)][k][l] += tmp;
          dp[i + 1][j][min(k + 1, B)][l] += tmp;
          dp[i + 1][min(j + 2, A)][k][l] += tmp;
          dp[i + 1][j][k][min(l + 1, C)] += tmp;
          dp[i + 1][min(j + 1, A)][min(k + 1, B)][l] += tmp;
        }
      }
    }
  }

  printf("%.9f\n", dp[N][A][B][C]);
}
