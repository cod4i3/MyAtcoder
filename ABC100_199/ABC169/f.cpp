
#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
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
  int N, S;
  cin >> N >> S;
  vector<mint> A(N);
  map<mint, mint> mp;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    mp[A[i]] += 1;
  }
  sort(A.begin(), A.end());
  if (A[0].x > S) {
    cout << 0 << endl;
    return 0;
  }

  vector<map<mint, mint>> pat;
  mint sum = 0;
  int l = 0, r = 0;
  while (l <= N) {
    while (r <= N && sum.x < S) sum += A[r++];
    if (sum.x == S) {
      map<mint, mint> v;
      for (int i = l; i < r; i++) {
        v[A[i]] += 1;
      }
      pat.emplace_back(v);
    }
    sum -= A[l++];
  }

  mint ans = 0;
  combination(3000);
  for (int i = 0; i < pat.size(); i++) {
    map<mint, mint> MP = pat[i];
    sum = 1;
    l = 0;
    for (pair<mint, mint> e : MP) {
      mint mul = combination(mp[e.first()], e.second();
      sum *= mul;
      l += e.second();
    }

    mint bin = pow(2, N - l);
    sum *= bin;
    ans += sum;
  }

  cout << ans << endl;
  return 0;
}