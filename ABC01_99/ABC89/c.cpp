#include <iostream>
using namespace std;
typedef long long ll;
bool seen[5];
ll cnt[5];

int main() {
  int N;
  cin >> N;
  string s[N];
  int kind = 0;
  for (int i = 0; i < N; i++) cin >> s[i];
  for (int i = 0; i < N; i++) {
    char f = s[i].at(0);
    if (f == 'M') {
      if (!seen[0]) {
        seen[0] = true;
        kind++;
      }
      cnt[0]++;
    }
    if (f == 'A') {
      if (!seen[1]) {
        seen[1] = true;
        kind++;
      }
      cnt[1]++;
    }
    if (f == 'R') {
      if (!seen[2]) {
        seen[2] = true;
        kind++;
      }
      cnt[2]++;
    }
    if (f == 'C') {
      if (!seen[3]) {
        seen[3] = true;
        kind++;
      }
      cnt[3]++;
    }
    if (f == 'H') {
      if (!seen[4]) {
        seen[4] = true;
        kind++;
      }
      cnt[4]++;
    }
  }
  if (N < 3) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      for (int k = j + 1; k < 5; k++) {
        ans += cnt[i] * cnt[j] * cnt[k];
      }
    }
  }

  if (ans <= 0) {
    cout << 0 << endl;
  } else
    cout << ans << endl;

  return 0;
}