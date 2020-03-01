#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  string str[11000];

  int cur = 0;
  REP(i, N) {
    REP(j, a[i]) {
      str[cur] = to_string(i + 1);
      cur++;
    }
  }

  string ans[H][W];
  cur = 0;
  REP(i, H) {
    if (i % 2 == 0) {
      REP(j, W) {
        ans[i][j] = str[cur];
        cur++;
      }
    } else {
      for (int j = W - 1; j >= 0; j--) {
        ans[i][j] = str[cur];
        cur++;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}