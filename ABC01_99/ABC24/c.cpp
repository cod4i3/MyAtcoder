#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N;
  int D, K;
  cin >> N >> D >> K;
  vector<pair<ll, ll>> M(D);
  FOR(i, D) {
    ll l, r;
    cin >> l >> r;
    M[i] = make_pair(l, r);
  }

  vector<pair<ll, ll>> P(K);
  FOR(i, K) {
    ll s, t;
    cin >> s >> t;
    P[i] = make_pair(s, t);
  }

    FOR(i, K) {
    ll cur = P[i].first, p = P[i].second;
    int ans = 0;
    if (cur < p) {
      FOR(j, D) {
        ll l = M[j].first, r = M[j].second;
        if (l <= cur && cur <= r) cur = r;
        if (cur >= p) {
          ans = max(ans, j);
          break;
        }
      }
    } else {
      FOR(j, D) {
        ll l = M[j].first, r = M[j].second;
        if (l <= cur && cur <= r) cur = l;
        if (cur <= p) {
          ans = max(ans, j);
          break;
        }
      }
    }
    cout << ans + 1 << endl;
  }

  return 0;
}