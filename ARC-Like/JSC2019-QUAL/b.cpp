
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main() {
  ll N, K;
  cin >> N >> K;

  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];

  ll res, ans = 0;
  for (ll i = 0; i < N; i++) {
    res = 0;
    for (ll j = 0; j < N; j++) {
      if (A[i] > A[j]) res++;
    }
    res = ((((K * (K - 1))) / 2) % mod) * res;
    res %= mod;
    ans = (ans + res) % mod;

    res = 0;
    for (ll j = i + 1; j < N; j++) {
      if (A[i] > A[j]) res++;
    }
    res = (res * K) % mod;
    ans = (ans + res) % mod;
  }

  cout << ans << endl;
  return 0;
}