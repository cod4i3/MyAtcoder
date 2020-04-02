#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
const int mod = 998244353;

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
  int N, S;
  cin >> N >> S;
  vector<int> A(N);
  FOR(i, N) cin >> A[i];
  int R = 0;
  mint sum = 0;
  mint cnt = 0;
  for (int L = 0; L < N; L++) {
    while (R < N && sum.x + A[R] <= S) {
      sum.x += A[R];
      if (sum.x == S) cnt.x += 1;
    }
    ll res += R - L;
    if (R == L)
      R++;
    else
      sum - A[L];
  }
}