#include <iostream>
#include <string>
using namespace std;

int main() {
  string s[3];
  for (int i = 0; i < 3; i++) cin >> s[i];

  // s[i]の長さ, current
  int idx[3] = {};
  int cur = 0;

  while (idx[cur] < s[cur].length()) {
    int next = s[cur][idx[cur]] - 'a';
    idx[cur]++;
    cur = next;
  }

  cout << char('A' + cur) << endl;
  return 0;
}
