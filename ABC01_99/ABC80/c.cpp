#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 10000000000
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  bool F[N][10];
  vector<vector<ll> > P(N, vector<ll>(10));
  vector<ll> sum(10, 0);
  REP(i, N) { REP(j, 10) cin >> F[i][j]; }
  REP(i, N) { REP(j, 11) cin >> P[i][j]; }

  ll ans = -INF;
  for (int mask = 1; mask < (1 << 10); mask++) {
    ll sum = 0;
    REP(i, N) {
      int cnt = 0;
      REP(j, 10) if (mask & 1 << j) if (F[i][j]) cnt++;
      sum += P[i][cnt];
    }
    ans = max(ans, sum);
  }

  cout << ans << endl;
  return 0;
}
