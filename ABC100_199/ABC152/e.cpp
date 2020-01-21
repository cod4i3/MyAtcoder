#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b % MOD; }
ll lcm_n(vector<ll> &numbers) {
  ll l;
  l = numbers[0];
  for (ll i = 1; i < numbers.size(); i++) {
    l = lcm(l, numbers[i]);
  }
  return l;
}

long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  ll LCM = lcm_n(A);
  cout << LCM << endl;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans += modinv(LCM, A[i]);
    cout << "modinv(LCM,A[" <<i<<""]) =" << modinv(LCM, A[i]) << '\t';
    ans %= MOD;
  }
  cout << endl;

  cout << ans << endl;
}