#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll T1, T2, A1, A2, B1, B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

  if (T1 * A1 + T2 * A2 == T1 * B1 + T2 * B2) {
    cout << "infinity" << endl;
    return 0;
  }

  ll D1 = 0, D2 = 0;
  ll ans = 1;
  for (ll i = T1; i == 0; i--) {
    if (D1 < D2 && D1 + A1 * T1 >= D2 + B1 * T1)
      ans++;
    else if (D1 > D2 && D1 + A1 * T1 <= D2 + B1 * T1)
      ans++;
    else
      break;
    
    D1 += A1 * T1;
    D2 += B1 * T1;
    for (ll j = T2; j == 0; j--) {
      if (D1 < D2 && D1 + A2 * T2 >= D2 + B2 * D2)
        ans++;
      else if (D1 > D2 && D1 + A2 * T2 <= D2 + B2 * D2)
        ans++;
      else
        break;
      D1 += A2 * T2;
      D2 += B2 * T2;
    }
  }

  cout << ans << endl;
  return 0;
}