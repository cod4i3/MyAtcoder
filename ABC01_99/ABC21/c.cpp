
#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
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
  vector<int> dist_a, dist_b;
  vector<bool> seen;
  vector<vector<int>> G;

  int N;
  cin >> N;
  G.resize(N);
  dist_a.resize(N, -1);
  dist_b.resize(N, -1);
  seen.resize(N, false);
  int a, b;
  cin >> a >> b;
  a--, b--;

  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].emplace_back(y);
    G[y].emplace_back(x);
  }

  dist_a[a] = 0;
  dist_b[b] = 0;

  queue<int> que;
  que.push(a);
  seen[a] = true;

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (int next_v : G[v]) {
      if (dist_a[next_v] != -1) continue;
      dist_a[next_v] = dist_a[v] + 1;
      que.push(next_v);
    }
  }

  que.push(b);
  seen[b] = true;
  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (int next_v : G[v]) {
      if (dist_b[next_v] != -1) continue;
      dist_b[next_v] = dist_b[v] + 1;
      que.push(next_v);
    }
  }


  vector<mint> cnt(N);
  for (int i = 0; i < N; i++) {
    if(dist_a[i] + dist_b[i] == dist_a[b]){
        cnt[dist_a[i]]++;
    }
  }

  mint ans = 1;
  for (int i = 0; i < dist_a[b]; i++) {
    ans *= cnt[i];
  }

  cout << ans.x << endl;
  return 0;
}