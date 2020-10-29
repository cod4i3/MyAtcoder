#include <iostream>
using namespace std;

int main() {
  int N, R;
  cin >> N >> R;
  string S;
  cin >> S;

  int r = -1;
  for (int i = N - 1; i >= 0; i--) {
    if (S[i] == '.') {
      r = i;
      break;
    }
  }
  if (r < 0 || R - 1 >= N) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  for (int i = 0; i <= r; i++) {
    if (i + R - 1 >= r) {
      if (S[r] == '.') ans += 1;
      break;
    }
    if (S[i] == '.') {
      for (int j = 0; j < R; j++) {
        if (i + j >= N) break;
        S[i + j] = 'o';
      }
      ans += 1;
    }
    ans += 1;
  }

  cout << ans << endl;
  return 0;
}