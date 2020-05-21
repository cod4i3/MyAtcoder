#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;

const int mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

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

  // 2のN乗を計算する
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
  cin >> N;
  vector<pair<ll, ll>> P(N);
  for (int i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    P[i] = make_pair(a, b);
  }

  map<pair<ll, ll>, ll> mp;
  for (int i = 0; i < N; i++) {
    pair<ll, ll> p1 = make_pair(P[i].first, P[i].second);
    if (p1.first < 0) p1.first *= -1;
    if (p1.second < 0) p1.second *= -1;

    if (p1.first != 0 && p1.second != 0) {
      ll GCD = gcd(p1.first, p1.second);
      P[i].first /= GCD, P[i].second /= GCD;
    }

    pair<ll, ll> p = make_pair(P[i].first, P[i].second);
    if (p.second < 0 && p.first < 0) {
      mp[make_pair(-p.first, -p.second)] += 1;
    } else if (p.second < 0) {
      mp[make_pair(-p.second, p.first)] += 1;
    } else if (p.first < 0) {
      mp[make_pair(p.second, -p.first)] += 1;
    } else {
      mp[make_pair(p.first, p.second)] += 1;
    }
  }

  mint len = mp.size();
  mint ans = 0;
  for (auto e : mp) {
    ans += (len - 1) * e.second;
  }
  cout << ans + len << endl;
  return 0;
}