#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  string s[N];
  int t[N];
  for (int i = 0; i < N; i++) {
    cin >> s[i] >> t[i];
  }
  string x;
  cin >> x;

  int start = 0;
  for (int i = 0; i < N; i++) {
    if (x == s[i]) start = i + 1;
  }

  int ans = 0;
  for (int i = start; i < N; i++) {
    ans += t[i];
  }

  cout << ans << endl;
  return 0;
}