#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;
  ll B = N;
  for (ll i = 1; i <= sqrt(N); i++) {
    if (N % i == 0) B = N / i;
  }
  ll ans = 1;
  while (B / 10 != 0) {
    B /= 10;
    ans++;
  }

  cout << ans << endl;
  return 0;
}