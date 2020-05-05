#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  vector<ll> sum(N + 1, 0);
  for (int i = 0; i < N; i++) sum[i + 1] = sum[i] + a[i];

  ll ans = 0;
  for (ll l = 0; sum[l] + K <= sum[N]; l++) {
    int r = lower_bound(sum.begin() + l, sum.end(), sum[l] + K) - sum.begin();
    ans += N - r + 1;
  }

  cout << ans << endl;
  return 0;
}