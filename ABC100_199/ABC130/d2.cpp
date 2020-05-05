#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int N;
  ll K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];

  int l = 0, r = 0;
  ll ans = 0, sum = 0;

  while (true) {
    while (r < N && sum < K) {
      sum += a[r++];
    }

    if (sum < K) break;
    ans += N - r + 1;
    sum -= a[l++];
  }

  cout << ans << endl;
  return 0;
}