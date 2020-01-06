#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll a, b, x;
  cin >> a >> b >> x;

  ll ans = b / x - a / x;
  if (a % x == 0) ans++;
  cout << ans << endl;
  return 0;
}