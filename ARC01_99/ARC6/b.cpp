#include <iostream>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, L;
  cin >> N >> L;
  string kuji[L + 1];
  for (int i = 0; i < L + 1; i++) cin >> kuji[i];

  // 横
  int goal;
  REP(i, N) if (kuji[L + 1][i] == 'o') goal = i;

  // 縦
  int Len = L;
  while (Len != 0) {
    if (goal != 0 or goal != 2 * N - 2) {
      if (kuji[Len][goal - 1] == '-') goal--;
      if (kuji[Len][goal + 1] == '-') goal++;
    } else if (goal == 0) {
      if (kuji[Len][goal + 1] == '-') goal++;
    } else {
      if (kuji[Len][goal - 1] == '-') goal--;
    }
    Len--;
  }

  cout << goal << endl;
  return 0;
}