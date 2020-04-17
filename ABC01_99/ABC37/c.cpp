#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];

  ll sum = 0;
  for (int i = 0; i < K; i++) sum += a[i];
  ll ans = sum;

  for (int i = K; i < N; i++) {
    sum += a[i];
    sum -= a[i - K];
    ans += sum;
  }

  cout << ans << endl;
  return 0;
}