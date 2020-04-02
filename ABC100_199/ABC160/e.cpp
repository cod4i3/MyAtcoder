#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  priority_queue<ll> que;
  vector<ll> p(A), q(B), r(C);
  FOR(i, A) cin >> p[i];
  FOR(i, B) cin >> q[i];
  FOR(i, C) cin >> r[i];
  sort(all(p), greater<ll>());
  sort(all(q), greater<ll>());
  sort(all(r), greater<ll>());
  FOR(i, X) que.push(p[i]);
  FOR(i, Y) que.push(q[i]);
  FOR(i, C) que.push(r[i]);
  ll ans = 0;
  FOR(i, X + Y) {
    ans += que.top();
    que.pop();
  }

  cout << ans << endl;
  return 0;
}
