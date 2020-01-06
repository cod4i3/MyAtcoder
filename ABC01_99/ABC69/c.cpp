#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int one = 0, two = 0, four = 0;
  REP(i, N) {
    int a;
    cin >> a;
    if (a % 4 == 0)
      four++;
    else if (a % 2 == 0)
      two++;
    else
      one++;
  }

  if (one <= four)
    cout << "Yes" << endl;
  else if (one == four + 1) {
    if (two)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  } else
    cout << "No" << endl;

  return 0;
}