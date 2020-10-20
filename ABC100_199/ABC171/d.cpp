#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0
#include <iostream>
#include <map>
#include <vector>
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  map<int, int> mp;
  ll ans = 0;
  int a;
  FOR(i, N) {
    cin >> a;
    mp[a] += 1;
    ans += a;
  }

  int Q;
  cin >> Q;
  FOR(i, Q) {
    ll b, c;
    cin >> b >> c;
    // cがmp[b]個増え、bがmp[b]個減る
    ans += c * mp[b] - b * mp[b];
    mp[c] += mp[b];
    mp[b] = 0;
    /*
    for (auto e : mp) {
      cout << "\t" << e.first << " " << e.second << endl;
    }
    */
    cout << ans << "\n";
  }

  return 0;
}