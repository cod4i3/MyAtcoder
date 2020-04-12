#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, X;
  cin >> n >> X;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (1 << i & X) ans += a[i];
  }
  cout << ans << endl;
  return 0;
}