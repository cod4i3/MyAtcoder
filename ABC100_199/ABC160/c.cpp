#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int K, N;
  cin >> K >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  int ans = A[N - 1] - A[0], len = N - 1;
  for (int i = 1; i < N; i++) {
    ans = min(K - A[i] + A[i - 1], ans);
  }
  cout << ans << endl;
  return 0;
}