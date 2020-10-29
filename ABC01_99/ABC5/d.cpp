#include <iostream>
#include <vector>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> D(N, vector<int>(N));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> D[i][j];

  // 横と縦の累積和
  vector<vector<int>> W(N, vector<int>(N, 0));
  vector<vector<int>> H(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) W[i][0] = D[i][0];
  for (int i = 0; i < N; i++) {
    for (int j = 1; j < N; j++) {
      W[i][j] = W[i][j - 1] + D[i][j];
    }
  }

  for (int j = 0; j < N; j++) H[0][j] = D[0][j];
  for (int j = 0; j < N; j++) {
    for (int i = 1; i < N; i++) {
      H[i][j] = H[i - 1][j] += D[i][j];
    }
  }

  int Q;
  cin >> Q;
  vector<int> P(Q);
  for (int i = 0; i < Q; i++) cin >> P[i];

  vector<int> ans(Q, 0);

  // 店員の番号
  for (int n = 0; n < Q; n++) {
    //cout << "n = " << n << endl;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        // 横の長さ
        for (int w = 1; w <= P[n]; w++) {
          int res = 0;
          // 縦の長さ
          int H = P[n] / w;
          if (H == 0) continue;
          //cout << "i = " << i << " j = " << j << endl;
          if (i + H > N) continue;
          if (j + w > N) continue;
          for (int h = 1; h <= H; h++) {
            //cout << "i = " << i << " j = " << j << " h = " << h << " w = " << w  << endl;
            if (w == 1) {
              //cout << "AAAA" << endl;
              res += D[i + h - 1][j];
            } else {
              //cout << "BBBB" << endl;
              // cout << W[i + h - 1][j + w - 1] << " ";
              // if (j > 0) cout << W[i + h - 1][j - 1] << endl;
              res += W[i + h - 1][j + w - 1];
              if (j > 0) res -= W[i + h - 1][j - 1];
            }
          }

          //cout << res << endl << endl;
          ans[n] = max(ans[n], res);
        }
      }
    }
    //cout << endl;
  }

  for (int i = 0; i < Q; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}