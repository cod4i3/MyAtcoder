#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll L, R;
  cin >> L >> R;

  ll ans = 2020;
  for (ll i = L; i <= L + 2017; i++) {
    for (ll j = i + 1; j <= L + 2018; j++) {
      ans = min(ans, (i * j) % 2019);
      if (j == R) break;
    }
    if (i + 1 == R) break;
  }

  cout << ans << endl;
  return 0;
}