#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int W;
  cin >> W;
  int N, K;
  cin >> N >> K;

  // +1だと失敗した
  int dp[N + 3][N + 3][W + 3];

  vector<int> A(N + 1);
  vector<int> B(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= N; j++) {
      for (int w = 0; w <= W; w++) {
        if (w + A[i] <= W) {
          dp[i + 1][j + 1][w + A[i]] =
              max(dp[i][j][w] + B[i], dp[i][j][w + A[i]]);
        }
        dp[i + 1][j][w] = max(dp[i + 1][j][w], dp[i][j][w]);
      }
    }
  }

  cout << dp[N][K][W] << endl;

  return 0;
}