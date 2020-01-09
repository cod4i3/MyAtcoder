#include <algorithm>
#include <iostream>
using namespace std;
#define MAX_N 110

int main() {
  int N;
  cin >> N;
  int A[2][N];
  for (int i = 0; i < N; i++) cin >> A[0][i];
  for (int i = 0; i < N; i++) cin >> A[1][i];
  int ans = 0, sum1 = 0, sum2 = 0;
  for (int i = 0; i < N; i++) {
    sum1 += A[0][i];
    sum2 = 0;
    for (int j = i; j < N; j++) sum2 += A[1][j];
    ans = max(ans, sum1 + sum2);
  }

  cout << ans << endl;
  return 0;
}