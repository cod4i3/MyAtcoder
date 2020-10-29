#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A), b(B);
  vector<int> sum(M);
  REP(i, A) cin >> a[i];
  REP(i, B) cin >> b[i];
  int minA = 10000000, minB = 10000000;
  int ans = *min_element(all(a)) + *min_element(all(b));

  REP(i, M) {
    int x, y, c;
    cin >> x >> y >> c;
    sum[i] = a[x - 1] + b[y - 1] - c;
    ans = min(ans, sum[i]);
  }

  cout << ans << endl;
  return 0;
}