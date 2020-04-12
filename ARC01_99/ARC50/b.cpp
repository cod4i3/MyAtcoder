#include <stdio.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define ll long long

int main() {
  long R, B;
  cin >> R >> B;
  long x, y;
  cin >> x >> y;
  // left,right
  long l = 0, r = 1e18;

  while (r - l > 1) {
    ll mid = (r + l) / 2;
    if (R - mid < 0 || B - mid < 0) {
      r = mid;
    } else if (mid <= (R - mid) / (x - 1) + (B - mid) / (y - 1)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << l << endl;
  return 0;
}
