#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  ll X, Y;
  cin >> X >> Y;
  vector<ll> a(N), b(M);
  FOR(i, N) cin >> a[i];
  FOR(i, M) cin >> b[i];

  bool curA = true;
  ll t = 0;
  int ans = 0;
  while (true) {
    if (curA) {
      t = *lower_bound(all(a), t);
      t += X;
      if (t > b[M - 1]) break;
    } else {
      t = *lower_bound(all(b), t);
      t += Y;
      if (t > a[N - 1]) {
        ans += 1;
        break;
      }
    }

    if (curA == false) ans += 1;
    curA ^= 1;
  }

  cout << ans << endl;
  return 0;
}