#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  string ans;
  int Q;
  cin >> ans >> Q;
  bool rev = false;
  int L = ans.length();

  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 1) rev ^= 1;

    if (t == 2) {
      if (ans.length() == L && rev == 1) {
        reverse(ans.begin(), ans.end());
        rev = 0;
      }
      int f;
      string c;
      cin >> f >> c;

      if ((f - 1) ^ rev) {
        ans += c;
      } else {
        ans.insert(0, c);
      }
    }
  }

  if (ans.length() == L && rev == 1) {
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
  }

  if (!rev) {
    cout << ans << endl;
  } else if (rev == 1) {
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }

  return 0;
}
