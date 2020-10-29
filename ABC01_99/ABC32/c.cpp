#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll max(ll a, ll b) { return (a > b ? a : b); }

int main() {
  ll N, K;
  cin >> N >> K;

  vector<ll> S;
  S.resize(N);
  for (int i = 0; i < N; i++) cin >> S[i];

  ll m = *min_element(S.begin(), S.end());
  if (m > K) {
    cout << 0 << endl;
    return 0;
  }
  if (m == 0) {
    cout << N << endl;
    return 0;
  }

  ll l = 0, r = 0;
  ll sum = 1;
  ll ans = 0;

  while (true) {
    while (r < N && sum * S[r] <= K) {
      sum *= S[r++];
    }
    if (sum == 0) sum = 1;
    ans = max(ans, r - l);
    if(l == N) break;
    if (l == r) r++;
    else sum /= S[l++];
  }

  cout << ans << endl;
  return 0;
}