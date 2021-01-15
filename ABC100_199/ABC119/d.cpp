#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<ll> s(A), t(B), x(Q);
  for (int i = 0; i < A; i++) cin >> s[i];
  for (int i = 0; i < B; i++) cin >> t[i];
  for (int i = 0; i < Q; i++) cin >> x[i];

  for (int i = 0; i < Q; i++) {
    int posS = distance(s.begin(), lower_bound(s.begin(), s.end(), x[i]));
    int posT = distance(t.begin(), lower_bound(t.begin(), t.end(), x[i]));
    ll ans = (1LL << 60);
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        if (posS - j < 0 || posT - k < 0) continue;
        ll S = s[posS - j], T = t[posT - k];
        ll res1 = abs(S - x[i]) + abs(T - S), res2 = abs(T - x[i]) + abs(S - T);
        ans = min({ans, res1, res2});
      }
    }
    cout << ans << '\n';
  }
  return 0;
}