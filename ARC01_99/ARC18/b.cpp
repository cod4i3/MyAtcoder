#include <iostream>
#include <vector>
#define REP2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  vector<pair<ll, ll>> plot(N);
  for (ll i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    plot[i] = make_pair(x, y);
  }

  ll ans = 0;
  REP2(i, 0, N - 2) {
    REP2(j, i + 1, N - 1) {
      REP2(k, j + 1, N) {
        pair<ll, ll> a = make_pair(plot[i].first - plot[k].first,
                                   plot[i].second - plot[k].second);
        pair<ll, ll> b = make_pair(plot[i].first - plot[j].first,
                                   plot[i].second - plot[j].second);
        ll S = abs(a.first * b.second - a.second * b.first);
        if (S % 2 == 0 && S != 0) ans += 1;
      }
    }
  }

  cout << ans << endl;
  return 0;
}