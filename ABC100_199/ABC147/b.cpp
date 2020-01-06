#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
  string s, c;
  cin >> s;
  c = s;
  reverse(c.begin(), c.end());
  int cnt;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != c[i]) cnt++;
  }

  cout << cnt / 2 << endl;
}