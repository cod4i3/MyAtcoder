#include <iostream>
using namespace std;

int main() {
  int n, k, m;
  cin >> n >> k >> m;
  int a[n], sum = 0;
  for (int i = 0; i < n - 1; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) sum += a[i];
  int ans = m * n - sum;
  if (ans > k)
    cout << -1 << endl;
  else if (ans >= 0)
    cout << ans << endl;
  if (ans < 0) cout << 0 << endl;
  return 0;
}
