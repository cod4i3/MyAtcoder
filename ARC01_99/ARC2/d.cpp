#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  bool con[15][15] = {};
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    con[x - 1][y - 1] = con[y - 1][x - 1] = 1;
  }

  int ans = 0;

  for (int bit = 0; bit < 1 << N; bit++) {
    int cnt = bitset<32>(bit).count();
    bool OK = true;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < i; j++) {
        if (bit >> i & bit >> j & 1 && !con[i][j]) OK = false;
      }
    }
    if (OK) ans = max(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}