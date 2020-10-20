#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int X, N;
  cin >> X >> N;
  vector<int> p(N);
  for (int i = 0; i < N; i++) cin >> p[i];
  int m = 10000;
  int ans = 0;
  for (int i = -100; i < 200; i++) {
    if (abs(X - i) < m) {
      bool flag = true;
      for (int j = 0; j < N; j++) {
        if (i == p[j]) flag = false;
      }
      if (!flag) continue;
      ans = i;
      m = abs(X - i);
    } else {
      continue;
    }
  }

  cout << ans << endl;
  return 0;
}