#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

ll calcProduct(ll n) {
  return (n == 1 || n == 0) ? 1 : n * calcProduct(n - 1) % MOD;
}

int main() {
  ll N;
  cin >> N;
  vector<ll> x(N);
  for (int i = 0; i < N; i++) cin >> x[i];
  vector<ll> sum(N, 0), d(N, 0);
  for (int i = 0; i < N - 1; i++) d[i] = x[i + 1] - x[i];
  REP(i, N - 1) cout << d[i] << ' ';
  cout << endl << endl;
  REP(i, N) {
    REP(j, N - 1) { sum[i] += abs(x[i] - x[j]) % MOD; }
    sum[i] %= MOD;
  }

  vector<ll> cost(N, 0);
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - 1; j++) {
      cost[i] += abs(sum[i] - sum[j]) % MOD;
    }
    cost[i] %= MOD;
  }

  ll ans = 0;
  for (int i = 0; i < N - 1; i++) {
    ans += cost[i];
    ans %= MOD;
  }
  cout << ans % MOD << endl;

  return 0;
}