/*
 縦ジャンプ (i+1, j+2)を A回, 横ジャンプ(i+2, j) B回とする
 （X, Y) = ( (2X - Y) / 3, (2Y - X) / 3)

*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
const int mod = 1000000007;

struct mint {
  ll x;  // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};

mint COM(ll n, ll k) {
  mint deno = 1;
  mint mole = 1;
  for (ll i = 0; i < k; i++) {
    deno *= n - i;
    mole *= (i + 1);
  }

  mint nCk = deno / mole;
  return nCk;
}

mint RepeatSquaring(mint N, ll P) {
  if (P == 0) return 1;
  if (P % 2 == 0) {
    mint t = RepeatSquaring(N, P / 2);
    return t * t;
  }
  return RepeatSquaring(N, P - 1) * N;
}

struct combination {
  vector<mint> fact, ifact;
  combination(int n) : fact(n + 1), ifact(n + 1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
};

int main() {
  mint X, Y;
  cin >> X.x >> Y.x;

  if ((2 * X.x - Y.x) % 3 != 0 || (2 * Y.x - X.x) % 3 != 0 || X.x * 2 < Y.x ||
      Y.x * 2 < X.x) {
    cout << 0 << endl;
    return 0;
  }

  mint A, B;
  A.x = (2 * X.x - Y.x) / 3;
  B.x = (2 * Y.x - X.x) / 3;

  mint ans = COM(A.x + B.x, A.x);
  cout << ans.x << endl;
}