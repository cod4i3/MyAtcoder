#pragma GCC optimize("Ofast")
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  set<int> s;
  vector<int> seen(N, 0);
  int a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    s,ins
    if(seen[a)
  }

  sort(A.begin(), A.end(), std::greater());

  // 割り切れる物は1とする
  for (int i = 0; i < N; i++) {
    if (seen[i]) continue;
    for (int j = i + 1; j < N; j++) {
      if (A[j] % A[i] == 0) {
        seen[j] = 1;
      }
      if (A[j] == A[i]) {
        seen[i] = 1;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (seen[i] == 0) ans++;
  }

  cout << ans << endl;
  return 0;
}
