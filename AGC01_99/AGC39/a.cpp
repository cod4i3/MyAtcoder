#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
  string s;
  char tmp;
  ll k;
  cin >> s >> k;
  ll cnt = 0, ans = 0;
  bool odd;

  //全部同じ
  bool same = true;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] != s[i - 1]) {
      same = false;
      break;
    }
    cnt++;
  }
  if (cnt % 2 == 0) odd = true;
  cnt = 0;

  if (same) {
    cout << (s.length() * k) / 2 << endl;
    return 0;
  }

  //ソート
  for (int i = 0; i < s.length(); i++) {
    if (s[0] == s[s.length() - 1]) {
      tmp = s[0];
      s.erase(s.begin());
      s += tmp;
    }
  }

  reverse(s.begin(), s.end());
  bool odd2;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] != s[i - 1]) break;
    cnt++;
  }
  if (cnt % 2 == 0) odd2 = true;
  cnt = 0;

  int start;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i - 1]) {
      cnt++;
    } else {
      start = i;
      break;
    }
  }
  ans += ((cnt + 1) / 2) * k;
  cout << ans << endl;
  cnt = 0;

  int ans1 = 0;
  for (int i = start; i < s.length(); i++) {
    if (s[i] == s[i - 1]) {
      cnt++;
    } else {
      ans1 += (cnt + 1) / 2;
      cnt = 0;
    }
  }
  ans1 += (cnt + 1) / 2;
  cout << ans1 << endl;
  ans += (ans1 * k);

  if (odd && !odd2) ans += k - 1;
  cout << ans << endl;
  return 0;
}