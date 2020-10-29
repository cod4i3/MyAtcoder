#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N;
  string C;
  cin >> N >> C;
  vector<string> s{"A", "B", "X", "Y"};
  vector<string> str;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      str.emplace_back(s[i] + s[j]);
    }
  }

  int ans = N;
  for (int i = 0; i < 15; i++) {
    for (int j = i + 1; j < 16; j++) {
      int res = N;
      for (int k = 0; k < N - 1; k++) {
        string cur = C.substr(k, 2);
        if (cur == str[i] || cur == str[j]) {
          res -= 1;
          k++;
        }
      }
      ans = min(ans, res);
    }
  }

  cout << ans << endl;
  return 0;
}