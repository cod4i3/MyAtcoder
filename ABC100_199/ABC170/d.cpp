#pragma GCC optimize("Ofast")
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;

  vector<int> A(N);
  vector<int> seen(1e6 + 10, 0);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    seen[A[i]]++;
  }
  sort(A.begin(), A.end());

  vector<bool> ok(1e6 + 10, true);
  for (int i = 1; i < 1e6 + 10; i++) {
    if (seen[i] > 0) {
      if (seen[i] >= 2) ok[i] = false;
      for (int j = i * 2; j < 1e6 + 1; j += i) {
        ok[j] = false;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++)
    if (ok[A[i]]) ans++;
  cout << ans << endl;
}
