#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  int ans = 0, cnt = 1;
  if (K == 1) {
    cout << N << endl;
    return 0;
  }
  for (int i = 1; i < N; i++) {
    if (A[i] > A[i - 1])
      cnt += 1;
    else
      cnt = 1;
    if (cnt >= K) ans += 1;
  }
  cout << ans << endl;
  return 0;
}
