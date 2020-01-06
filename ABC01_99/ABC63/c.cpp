#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int s[110];
  bool flag = true;
  int ans = 0;
  int minus;
  for (int i = 0; i < N; i++) {
    cin >> s[i];
    if (s[i] % 10 != 0) flag = false;
    ans += s[i];
  }

  if (flag) {
    cout << 0 << endl;
    return 0;
  }

  sort(s, s + N);

  if (ans % 10 == 0) {
    for (int i = 0; i < N; i++) {
      if ((ans - s[i]) % 10 != 0) {
        ans -= s[i];
        break;
      }
    }
  }

  cout << ans << endl;
}