#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll N, C, K;
  cin >> N >> C >> K;
  vector<ll> T(N);
  for (int i = 0; i < N; i++) cin >> T[i];
  sort(T.begin(), T.end());

  ll ans = 0;
  for (int i = 0; i < N;) {
    ans++;
    if (i >= N) break;
    ll start = i;
    while (i < N && T[i] - T[start] <= K && i - start < C) i++;
  }

  cout << ans << endl;
  return 0;
}