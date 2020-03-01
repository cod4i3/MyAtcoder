#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
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

mint RepeatSquaring(mint N, ll P) {
  if (P == 0) return 1;
  if (P % 2 == 0) {
    mint t = RepeatSquaring(N, P / 2);
    return t * t;
  }
  return RepeatSquaring(N, P - 1) * N;
}

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // 前処理
  // COMinit();
  mint n, a, b;
  cin >> n.x >> a.x >> b.x;

  mint ans = RepeatSquaring(2, n.x);
  ans -= 1;

  ans -= COM(n.x, a.x);
  ans -= COM(n.x, b.x);
  cout << ans.x << endl;
}
