#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string w;
  cin >> w;

  int cnt = 0;
  bool flag = true;
  for (char c : w) {
    for (int i = 0; i < w.length(); i++) {
      if (c == w[i]) cnt++;
    }

    if (cnt % 2 != 0) {
      flag = false;
      break;
    }
  }

  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
