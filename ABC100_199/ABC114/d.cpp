#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  ll ans = 0, dist;
  int v = 0;
  for (int i = 2; i <= N; i++) {
    cout << "? " << 1 << " " << i << endl;
    cin >> dist;
    if (dist > ans) {
      ans = dist;
      v = i;
    }
  }

  for (int i = 1; i <= N; i++) {
    if (i == v) continue;
    cout << "? " << v << " " << i << endl;
    cin >> dist;
    ans = max(ans, dist);
  }
  cout << "! " << ans << endl;
  return 0;
}