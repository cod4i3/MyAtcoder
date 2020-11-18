#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), sum(N, 0);
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  sum[0] = A[0];
  for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + A[i];

  ll ans = 1;
  for (int i = N - 2; i >= 0; i--) {
    if (sum[i] * 2 >= A[i + 1])
      ans++;
    else
      break;
  }

  cout << ans << endl;
  return 0;
}