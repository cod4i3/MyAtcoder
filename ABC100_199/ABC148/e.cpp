#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

ll PowMod(ll N, ll P) {
  if (P == 0) return 1;
  if (P % 2 == 0) {
    ll t = PowMod(N, P / 2);
    return t * t;
  }
  return N * PowMod(N, P - 1);
}

int main() {
  ll N;
  cin >> N;
  ll ans;
  if (N % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }

  ll digit = 0;
  while (N / 10 != 0) {
    digit++;
    N /= 10;
  }
  ll top = N;
  ll nine = 0;
  cout << ans << endl;
  while (digit != 0) {
    cout << top << " " << PowMod(9, nine) << ' ' << nine << ' ' << digit << " "
         << endl;
    ans += top * PowMod(9, nine) * digit;
    digit--;
    nine++;
  }

  cout << ans << endl;
  return 0;
}