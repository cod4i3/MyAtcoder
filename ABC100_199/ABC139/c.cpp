#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> H(N);
  for (int i = 0; i < N; i++) cin >> H[i];
  ll ans = 0, cnt = 0, cur = H[0];

  for (int i = 1; i < N; i++) {
    if (H[i] <= cur)
      cnt += 1;
    else
      cnt = 0;

    cur = H[i];
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}