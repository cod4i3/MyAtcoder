#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
typedef long long ll;

int main() {
  ll N;
  cin >> N;
  string ans = "";
  if (!N) {
    cout << '0' << endl;
    return 0;
  }
  while (N) {
    ll r = N % 2;
    if (r < 0) r += 2;
    ans += to_string(r);
    N = (N - r) / (-2);
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}