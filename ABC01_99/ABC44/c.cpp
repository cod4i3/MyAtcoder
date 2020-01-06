#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

int main(void) {
  ll n, s;
  cin >> n >> s;
  if (s == 1) {
    cout << n << endl;
    return 0;
  } else if (n == s) {
    cout << 1 << endl;
    return 0;
  }
  ll b;

  bool flag;
  for (b = 2; b <= sqrt(n); b++) {
    ll sum = 0, ans = n;
    while (ans % b != 0) {
      sum += ans % b;
      ans /= b;
    }

    if (sum == s) {
      flag = true;
      break;
    }
  }

  if (flag)
    cout << b << endl;
  else
    cout << -1 << endl;
}