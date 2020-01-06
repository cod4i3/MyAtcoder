#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define MAX_N 10010
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<ll> a(N + 1, 0), cnt(N + 1, 0);

  ll ans = 0;
  REP(i, N) {
    cin >> a[i];
    (a[i] > N) ? ans++ : cnt[a[i]]++;
  }
  REP(i, N + 1) {
    if (cnt[i] < i)
      ans += cnt[i];
    else if (cnt[i] > i)
      ans += cnt[i] - i;
  }

  cout << ans << endl;
  return 0;
}