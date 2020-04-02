
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;
#define FOR(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N), B(N);
  FOR(i, N) {
    cin >> A[i];
    B[i] = A[i];
  }
  sort(all(A));
  // FOR(i, N) cout << A[i] << endl;

  vector<ll> cnt(N + 1, 0);
  FOR(i, N) {
    if (cnt[A[i]] != 0) continue;
    auto iter_upper = upper_bound(all(A), A[i]);
    ll idx_upper = distance(A.begin(), iter_upper);
    auto iter_lower = lower_bound(all(A), A[i]);
    ll idx_lower = distance(A.begin(), iter_lower);
    cnt[A[i]] = idx_upper - idx_lower;
  }
  /*
  cout << "cnt = " << endl;
  FOR(i, N) cout << cnt[i] << " ";
  cout << endl;
  */

  // N*(N-1)/2
  vector<ll> C(N + 1, 0);
  FOR(i, N) C[A[i]] = cnt[A[i]] * (cnt[A[i]] - 1) / 2;
  // (N-1)*(N-2)/2
  vector<ll> D(N + 1, 0);
  FOR(i, N) D[A[i]] = (cnt[A[i]] - 1) * (cnt[A[i]] - 2) / 2;
  ll sum = accumulate(all(C), 0LL);

  // cout << " ans = " << endl;
  FOR(i, N) {
    ll ans = sum - C[B[i]] + D[B[i]];
    cout << ans << endl;
  }
  // cout << endl;

  return 0;
}
