#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N, C;
  cin >> N >> C;

  vector<vector<int>> D(C, vector<int>(C));
  for (int i = 0; i < C; i++)
    for (int j = 0; j < C; j++) cin >> D[i][j];

  vector<vector<int>> color(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> color[i][j];
      color[i][j]--;
    }
  }

  vector<vector<ll>> dif(3, vector<ll>(C));
  for (int c = 0; c < C; c++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dif[(i + j) % 3][c] += D[color[i][j]][c];
      }
    }
  }


  ll ans = (1 << 30);
  vector<int> num = {0, 1, 2};
  for (int i = 0; i < C - 2; i++) {
    for (int j = i + 1; j < C - 1; j++) {
      for (int k = j + 1; k < C; k++) {
        do {
          ll res = 0;
          int n0 = num[0], n1 = num[1], n2 = num[2];
          if (dif[n0].size()) res += dif[n0][i];
          if (dif[n1].size()) res += dif[n1][j];
          if (dif[n2].size()) res += dif[n2][k];
          ans = min(ans, res);
        } while (next_permutation(num.begin(), num.end()));
      }
    }
  }

  cout << ans << endl;
  return 0;
}