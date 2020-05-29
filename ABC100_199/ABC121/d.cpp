#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ll A, B;
  cin >> A >> B;
  ll ans = 0;
  if (B - A < 4) {
    for (ll i = A; i <= B; i++) {
      ans ^= i;
    }
    cout << ans << endl;
    return 0;
  }

  while (A % 4 != 0) ans ^= A++;
  while (B % 4 != 3) ans ^= B--;

  cout << ans << endl;
  return 0;
}