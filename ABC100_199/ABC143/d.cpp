#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++) cin >> L[i];
  sort(L.begin(), L.end());

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int d = distance(lower_bound(L.begin(), L.end(), L[i] + L[j]), L.end());
      ans += (N - 1 - j) - d;
    }
  }

  cout << ans << endl;
  return 0;
}