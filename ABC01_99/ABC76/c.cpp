#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  bool flag = false;
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  for (int i = 0; i < s.length(); i++) {
    int cnt = 0;
    if (!flag)
      for (int j = 0; j < t.length(); j++)
        if (s[i + j] == t[j] || s[i + j] == '?') cnt++;

    if (cnt == t.length()) {
      flag = true;
      for (int k = 0; k < t.length(); k++) s[i + k] = t[k];
    }
  }

  for (int i = 0; i < s.length(); i++)
    if (s[i] == '?') s[i] = 'a';

  reverse(s.begin(), s.end());

  if (!flag)
    cout << "UNRESTORABLE" << endl;
  else
    cout << s << endl;
  return 0;
}