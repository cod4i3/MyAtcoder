#include <iostream>
using namespace std;

int main() {
  int c[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> c[i][j];
    }
  }

  bool flag = false;
  int c2[3][3];
  for (int up = 0; up <= 100; up++) {
    for (int mid = 0; mid <= 100; mid++) {
      for (int down = 0; down <= 100; down++) {
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            c2[i][j] = c[i][j];
          }
        }
        for (int i = 0; i < 3; i++) c2[0][i] -= up;
        for (int i = 0; i < 3; i++) c2[1][i] -= mid;
        for (int i = 0; i < 3; i++) c2[2][i] -= down;

        int cnt = 0;
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 3; j++) {
            if (c2[i][j] == c2[i + 1][j]) cnt++;
          }
        }
        if (cnt == 6) flag = true;
      }
    }
  }

  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}