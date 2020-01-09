#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int N, H;
  cin >> N >> H;
  vector<ll> a(N), b(N);
  for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());

  ll sum = 0, cnt = 0, ans = 0;
  for (int i = 0; i < N; i++) {
    if (b[i] < a[0]) break;
    cnt++;
    sum += b[i];
    ans = ((H - sum) + (a[0] - 1)) / a[0];
    if (sum >= H) {
      cout << cnt << endl;
      return 0;
    }
  }

  if (ans == 0 && cnt == 0) {
    ans = (H + (a[0] - 1)) / a[0];
    cout << ans << endl;
  } else
    cout << ans + min(cnt, ll(b.size())) << endl;

  return 0;
}