#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  ll x[N];
  for (int i = 0; i < N; i++) cin >> x[i];

  ll ans = 10000000000;
  for (int i = 0; i < N; i++) {
    if (i + K > N) break;
    ll sum, l = x[i], r = x[i + K - 1];
    sum = min(abs(l) + abs(r - l), abs(r) + abs(r - l));
    ans = min(sum, ans);
  }

  cout << ans << endl;
  return 0;
}