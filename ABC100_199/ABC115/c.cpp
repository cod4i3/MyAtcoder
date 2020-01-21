#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> h(N);
  for (int i = 0; i < N; i++) cin >> h[i];
  sort(all(h));

  ll ans = 1000000000;
  for (int i = 0; i + K - 1 < N; i++) {
    ans = min(ans, h[i + K - 1] - h[i]);
  }

  cout << ans << endl;
}