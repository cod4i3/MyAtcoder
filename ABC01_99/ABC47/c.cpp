#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  int cnt = 0;
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] != s[i + 1]) cnt++;
  }

  cout << cnt << endl;
  return 0;
}