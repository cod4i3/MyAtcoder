#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<pair<char, char> > m(10);
  m[1] = make_pair('b', 'c');
  m[2] = make_pair('d', 'w');
  m[3] = make_pair('t', 'j');
  m[4] = make_pair('f', 'q');
  m[5] = make_pair('l', 'v');
  m[6] = make_pair('s', 'x');
  m[7] = make_pair('p', 'm');
  m[8] = make_pair('h', 'k');
  m[9] = make_pair('n', 'g');
  m[0] = make_pair('z', 'r');

  vector<string> w(N);
  FOR(i, N) cin >> w[i];
  bool first = true;
  vector<string> ans;

  FOR(i, N) {
    string str = "";
    FOR(k, w[i].length()) {
      FOR(j, 10) {
        string word = w[i];
        char f = m[j].first, s = m[j].second;
        if (word[k] == f || word[k] == s || word[k] == char(f - 'a' + 'A') ||
            word[k] == char(s - 'a' + 'A')) {
          str += to_string(j);
        }
      }
    }
    if (str != "") ans.emplace_back(str);
  }

  while (!ans.empty()) {
    cout << ans[0];
    ans.erase(ans.begin());
    if (ans.empty()) break;
    cout << " ";
  }
  cout << endl;
  return 0;
}