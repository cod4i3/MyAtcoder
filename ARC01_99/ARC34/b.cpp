#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  ll N = stoll(S);

  int l = S.length();
  ll x = 0, res = 0, fx = 0;
  vector<ll> ans;
  for (int k = 0; k <= l * 9; k++) {
    if (k >= N) break;
    fx = 0;
    x = N - k;
    res = x;
    while (res) {
      fx += res % 10;
      res /= 10;
    }
    if (fx + x == N) ans.emplace_back(x);
  }

  cout << int(ans.size()) << endl;
  sort(ans.begin(), ans.end());
  for (int i = 0; i < int(ans.size()); i++) cout << ans[i] << endl;
  return 0;
}