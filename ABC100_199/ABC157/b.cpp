#include <iostream>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
bool bingo[3][3];

int main() {
  string A[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> A[i][j];
    }
  }

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string b;
    cin >> b;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (b == A[i][j]) bingo[i][j] = true;
      }
    }
  }

  REP(i, 3) {
    if (bingo[i][0] && bingo[i][1] && bingo[i][2]) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  REP(i, 3) {
    if (bingo[0][i] && bingo[1][i] && bingo[2][i]) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  if (bingo[0][0] && bingo[1][1] && bingo[2][2]) {
    cout << "Yes" << endl;
    return 0;
  }

  if (bingo[2][0] && bingo[1][1] && bingo[0][2]) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
  return 0;
}