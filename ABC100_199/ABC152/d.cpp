#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_N 2000000

int main() {
  int N;
  cin >> N;

  vector<vector<int>> digitA(9, vector<int>(9));
  vector<vector<int>> digitB(9, vector<int>(9));
  for (int i = 1; i <= N; i++) {
    if(i % 10 == 0) continue;
    int down = i % 10;
    int top = i;
    while (top >= 10) {
      top /= 10;
    }
    top--, down--;
    digitA[top][down]++;
    digitB[top][down]++;
  }

  int ans = 0;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
       ans += digitA[i][j] * digitB[j][i];
    }
  }

  cout << ans << endl;
  return 0;
}