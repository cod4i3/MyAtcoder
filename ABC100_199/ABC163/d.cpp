
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;
const int mod = 1000000007;
const int MAX = 300000;

int main() {
  ll N, K;
  cin >> N >> K;

  ll ans = 0;
  // iはllにしないと酷いことになる
  for (ll i = K; i <= (N + 1); i++) {
    ll max = (N * 2 - i + 1) * i / 2;
    ll min = (i - 1) * i / 2;
    ans += max - min + 1;
    ans %= mod;
  }

  cout << ans << endl;
}