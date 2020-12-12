#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll x, y, z, K;
  cin >> x >> y >> z >> K;
  vector<ll> a(x), b(y), c(z);
  for (int i = 0; i < x; i++) cin >> a[i];
  for (int i = 0; i < y; i++) cin >> b[i];
  for (int i = 0; i < z; i++) cin >> c[i];

  sort(a.begin(), a.end(), greater<ll>());
  sort(b.begin(), b.end(), greater<ll>());
  sort(c.begin(), c.end(), greater<ll>());

  vector<ll> ab;
  for (int i = 0; i < x; i++)
    for (int j = 0; j < y; j++) ab.emplace_back(a[i] + b[j]);
  sort(ab.begin(), ab.end(), greater<ll>());

  vector<ll> ans;
  for (int i = 0; i < z; i++) {
    for (int j = 0; j < min(ll(ab.size()), K); j++) {
      ans.emplace_back(ab[j] + c[i]);
    }
  }

  sort(ans.begin(), ans.end(), greater<ll>());
  for (int i = 0; i < K; i++) cout << ans[i] << endl;
  return 0;
}