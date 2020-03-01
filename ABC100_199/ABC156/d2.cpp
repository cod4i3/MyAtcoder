#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long int;
const ll mod = 1000000007;

ll PowMod(ll n, ll p, ll m) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    ll t = PowMod(n, p / 2, m);
    return t * t % m;
  }
  return n * PowMod(n, p - 1, m) % m;
}

ll COM(ll n, ll r) {
  // 分母と分子。いい名前思いつかなかった
  ll res, deno, mole;
  res = deno = mole = 1;
  for (int i = 0; i < r; i++) {
    mole *= (n - i);
    mole %= mod;
    deno *= (r - i);
    deno %= mod;
  }
  // 分母の逆元
  res = PowMod(deno, mod - 2, mod);
  res = (res * mole) % mod;
  return res;
}

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  ll ans = PowMod(2, n, mod) - 1;
  ll diff = (COM(n, a) + COM(n, b)) % mod;
  cout << (ans - diff + mod) % mod << endl;
}
