#include <iostream>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  string s;
  cin >> s;
  if (s.find('0') == -1) {
    cout << s.length() << endl;
    return 0;
  }

  int right = 0;
  int ans = 0, res = 0, cnt = 0;
  for (int left = 0; left < s.length() - 1; left++) {
    if (s[left] == '0' && s[left + 1] == '1') {
      cnt--;
      left++;
    }
    while (cnt < K + 1) {
      if (right == s.length()) break;
      right++;
      if (s[right] == '0' && s[right + 1] == '1') cnt++;
      if (s[right] == '1' && s[right + 1] == '0') break;
    }
    ans = max(ans, right - left);
  }

  cout << ans << endl;
}