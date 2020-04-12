#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

bool comp(const std::string& lh, const std::string& rh) {
  return lh.length() < rh.length();
}

int main() {
  int b[10];
  FOR(i, 10) cin >> b[i];
  int N;
  cin >> N;
  vector<pair<string, string> > a(N);
  FOR(i, N) {
    string s;
    cin >> s;
    a[i] = make_pair(s, s);
  }

  FOR(i, N) {
    FOR(j, a[i].second.length()) {
      FOR(k, 10)
      if (b[k] == a[i].second[j] - '0') a[i].first[j] = char('0' + k);
    }
  }

  vector<pair<ll, string> > ans(N);
  FOR(i, N) ans[i] = make_pair(stoll(a[i].first), a[i].second);
  sort(ans.begin(), ans.end());

  FOR(i, N) cout << ans[i].second << endl;
  return 0;
}
