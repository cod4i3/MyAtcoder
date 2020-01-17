#include <algorithm>
#include <iostream>
using namespace std;
int scnt[26], tcnt[26];
int main() {
  string s, t;
  cin >> s >> t;
  for (char c = 'a'; c <= 'z'; c++) {
    for (int i = 0; i < s.length(); i++) {
      int cur = c - 'a';
      if (s.at(i) == c) scnt[cur] += 1;
      if (t.at(i) == c) tcnt[cur] += 1;
    }
  }

  sort(scnt, scnt + 26);
  sort(tcnt, tcnt + 26);
  for (int i = 0; i < 26; i++) {
    if (scnt[i] != tcnt[i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}