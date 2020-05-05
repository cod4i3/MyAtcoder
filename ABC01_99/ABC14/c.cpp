#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MAX_N = 1100000;

int main() {
  int N;
  cin >> N;
  vector<pair<ll, ll>> r(N);
  for (int i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    r[i] = make_pair(a, b);
  }

  vector<ll> c(MAX_N, 0);
  for (int i = 0; i < N; i++) {
    c[r[i].first] += 1;
    c[r[i].second + 1] -= 1;
  }

  vector<ll> sum(MAX_N, 0);
  sum[0] = c[0];
  for (int i = 1; i < MAX_N; i++) {
    sum[i] = sum[i - 1] + c[i];
  }

  ll ans = 0;
  for (int i = 0; i <= MAX_N; i++) ans = max(ans, sum[i]);
  cout << ans << endl;
  return 0;
}