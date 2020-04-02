#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = mod - inv[mod % i] * (mod / i) % mod;
    finv[i] = finv[i - 1] * inv[i] % mod;
  }
}

// 二項係数計算
long long COM(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

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
  ll N;
  string S;
  cin >> N >> S;
  vector<int> alpha(26, 0);
  for (int i = 0; i < S.length(); i++) alpha[S[i] - 'a']++;
  mint ans = 0;
  int cnt = 0;
  for (int i = 0; i < 26; i++)
    if (alpha[i]) cnt += alpha[i];
  for (int i = 0; i < alpha.size(); i++) ans += alpha[i];
  COMinit();

  cout << ans.x << endl;
  cout << cnt << endl;
  cout << "loop" << endl;
  for (int i = 2; i <= cnt; i++) {
    ll plus = COM(cnt, i);
    for (int j = 0; j < 26; j++) {
      if (alpha[j] > 1 && i - 2) plus -= COM(alpha[j], 2) * COM(cnt - 2, i - 2);
    }
    ans += plus;
  }

  cout << ans.x << endl;
  return 0;
}