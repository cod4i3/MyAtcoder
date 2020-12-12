#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N + 30);
  vector<bool> seen(1e5 + 1000, false);
  for (int i = 0; i < N; i++) cin >> A[i];

  int r = 0, ans = 0;
  for (int l = 0; l < N; l++) {
    for (; r < N && !seen[A[r]]; r++) {
        seen[A[r]] = true;
        ans = max(ans, r - l + 1);
    }
    seen[A[l]] = false;
  }

  cout << ans << endl;
  return 0;
}