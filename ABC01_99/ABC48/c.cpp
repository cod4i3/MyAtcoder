#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll N, x;
  cin >> N >> x;

  ll a[N];
  for (int i = 0; i < N; i++) cin >> a[i];

  ll ans = 0;
  for (int i = 0; i < N - 1; i++) {
    if (a[i] + a[i + 1] > x) {
        
      ans += a[i + 1] + a[i] - x;

      if (a[i] >= x) {
        a[i + 1] = 0;
        a[i] = x;
      } else
        a[i + 1] = x - a[i];
    }
  }

  cout << ans << endl;
  return 0;
}