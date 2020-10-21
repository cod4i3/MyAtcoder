#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;

  vector<string> c(H);
  for (int i = 0; i < H; i++) cin >> c[i];

  int ans = 0;

  vector<string> C(H);
  for (int bit = 0; bit < (1 << H); bit++) {
    for (int bit2 = 0; bit2 < (1 << W); bit2++) {
      copy(c.begin(), c.end(), C.begin());

      for (int h = 0; h < H; h++) {
        if ((1<<h) & bit) C[h] = string(W, '.');
        for (int w = 0; w < W; w++) {
          if ((1 << w) & bit2) C[h][w] = '.';
        }
      }

      int sum = 0;
      for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
          if (C[i][j] == '#') sum++;
        }
      }

      if(sum == K) ans += 1;
    }
  }

  cout << ans << endl;
  return 0;
}