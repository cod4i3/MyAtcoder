#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  for (int i = S.length() - 3; i >= 0; i -= 2) {
    bool flag = true;
    for (int j = 0; j <= i / 2; j++) {
      if (S.at(j) != S.at(j + i / 2 + 1)) flag = false;
      /*
    else
      cout << "j=" << j << "   j + i / 2 + 1= " << j + i / 2 + 1 << endl
           << S.at(j) << ' ' << S.at(j + i / 2 + 1) << endl;
           */
    }

    if (flag) {
      cout << i + 1 << endl;
      break;
    }
  }
  return 0;
}