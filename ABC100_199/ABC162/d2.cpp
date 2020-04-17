#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  ll r = 0, g = 0, b = 0;
  FOR(i, N) {
    if (S[i] == 'R') r++;
    if (S[i] == 'G') g++;
    if (S[i] == 'B') b++;
  }

  ll ans = r * g * b;
  FOR(i, N) {
    FOR2(j, i + 1, N) {
      if (S[i] == S[j]) continue;
      int k = 2 * j - i;
      if (k >= N || S[k] == S[i] || S[k] == S[j]) continue;
      ans--;
    }
  }

  cout << ans << endl;
  return 0;
}
