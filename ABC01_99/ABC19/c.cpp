#pragma GCC optimize("Ofast")
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<ll> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  bool seen[N];
  fill(seen, seen + N, false);

  sort(a.begin(), a.end());
  ll m = a[N - 1];

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (seen[i]) continue;
    seen[i] = true;
    ll cur = a[i];
    while (true) {
      if (cur > m) break;
      if (binary_search(a.begin(), a.end(), cur * 2)) {
        auto itr = lower_bound(a.begin(), a.end(), 2 * cur);
        int dis = distance(a.begin(), itr);
        seen[dis] = true;
      }
      cur *= 2;
    }

    ans += 1;
  }

  cout << ans << endl;
  return 0;
}