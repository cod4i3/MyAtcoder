#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  vector<ll> sum(N, 0);
  sum[0] = a[0];
  for (int i = i; i < N; i++) sum[i] = sum[i - 1] + a[i];

  ll cur = 0, ans = 0;
  int right = 0;
  for (int left = 0; left < N; left++) {
    while (cur < K) {
      cur += a[right];
      right++;
    }

    while (cur >= K) {
      cur -= a[left];
      left++;
    }

    if (left < N) ans += left;
  }

  cout << ans << endl;
  return 0;
}