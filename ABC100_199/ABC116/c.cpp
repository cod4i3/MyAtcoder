#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++
#define all(x) (x).begin(), (x).end()

int main() {
  int N;
  cin >> N;
  vector<int> h(N);
  int ans = 0;
  for (int i = 0; i < N; i++) cin >> h[i];
  if (max_element(all(h)) == min_element(all(h))) {
    cout << *max_element(all(h)) << endl;
    return 0;
  }
  while (1) {
    int l = -1;
    int r = N;
    for (int i = 0; i < N; i++) {
      if (l < 0 && h[i] > 0) l = i;
      if (i > 0 && h[i] <= 0 && h[i - 1] > 0) {
        r = i;
        break;
      }
    }
    if (l < 0) l = 0;
    int hmin = 1000;
    for (int i = l; i < r; i++)
      if (h[i] > 0) hmin = min(hmin, h[i]);

    for (int i = l; i < r; i++) {
      h[i] -= hmin;
    }
    ans += hmin;

    int hmax = *max_element(h.begin(), h.end());
    if (hmax <= 0) break;
  }
  cout << ans << endl;
}
