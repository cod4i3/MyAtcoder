#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  if(N % 2){
      cout << 0 << endl;
      return 0;
  }
  ll cnt = 0, res = N;
  while (res) {
    res /= 5;
    cnt++;
  }
  ll ans = 0, x = 5;
  for (ll i = 0; i <= cnt; i += 1, x *= 5) {
    if(ll(2 * x) > N) break;
    ans += N / ll(ll(2) * x);
  }
  cout << ans << endl;
  return 0;
}