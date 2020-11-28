//まだWA
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
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
  mint& operator++() {
    *this += 1;
    return *this;
  }
  mint operator++(int) {
    auto tmp = *this;
    *this += 1;
    return tmp;
  }
  mint& operator--() {
    *this -= 1;
    return *this;
  }
  mint operator--(int) {
    auto tmp = *this;
    *this -= 1;
    return tmp;
  }

  // XのN乗を計算する
  // よく使う2^Nならmint(2).pow(len)
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

istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

int main() {
  int N;
  string S;
  cin >> N >> S;

  vector<ll> c(26, 0);
  for (int i = 0; i < N; i++) {
    c[S[i] - 'a']++;
  }

  int cnt = 0;
  for (int i = 0; i < 26; i++) {
    if (c[i] > 0) cnt++;
  }

  mint ans = 1, res = 0;
  // 選び方は 0 ~ c[i]
  for (int i = 0; i < 26; i++) {
    if (!c[i]) continue;
    res = c[i] + 1;
    ans *= res;
  }

  // 全てが0のパターン
  ans -= 1;

  cout << ans << endl;
}