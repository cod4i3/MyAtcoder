#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<pair<ll, ll>> bt(N);
  vector<ll> cnt(N, 0);
  for (int i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    a %= b;
    bt[i] = make_pair(a, b);
  }

  ll ans = 0, sum = 0;
  for (int i = N - 1; i >= 0; i--) {
    ll a = bt[i].first, b = bt[i].second;
    if (a) {
      sum += b - a;
      ans += b - a;
    }
    if (i != 0) {
      bt[i - 1].first += sum;
      bt[i - 1].first %= bt[i - 1].second;
    }
  }

  cout << ans << endl;
  return 0;
}