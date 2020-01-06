#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  int l = -1, r = -1;
  for (int i = 0; i < s.length() - 1; i++) {
    if (s.at(i) == s.at(i + 1)) {
      l = i + 1;
      r = i + 2;
      break;
    }
  }

  for (int i = 0; i < s.length() - 2; i++) {
    if (s.at(i) == s.at(i + 2)) {
      l = i + 1;
      r = i + 3;
      break;
    }
  }

  cout << l << " " << r << endl;
}
