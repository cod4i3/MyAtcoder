#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N), C(N);
  FOR(i, N) cin >> A[i];
  FOR(i, N) cin >> B[i];
  FOR(i, N) cin >> C[i];
  sort(all(A));
  sort(all(B));
  sort(all(C));
  ll ans = 0;
  FOR(i, N) {
    auto itr_a = lower_bound(all(A), B[i] );
    auto itr_c = upper_bound(all(C), B[i] );
    ll idx_a = distance(A.begin(), itr_a);
    ll idx_c = C.size() - distance(C.begin(), itr_c);
    ans += idx_a * idx_c;
  }
  cout << ans << endl;
  return 0;
}