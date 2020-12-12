// 嘘解法
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N, C;
  cin >> N >> C;

  vector<ll> Cum(1e5 + 1000, 0);
  for (int i = 0; i < N; i++) {
    ll s, t, c;
    cin >> s >> t >> c;
    s--, t--;
    Cum[s]++;
    Cum[t + 1]--;
  }

  ll ans = 0;
  for (int i = 1; i <= 1e5; i++) {
    Cum[i] += Cum[i - 1];
    ans = max(ans, Cum[i]);
  }

  cout << min(ans, ll(C)) << endl;
  return 0;
}