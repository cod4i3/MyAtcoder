#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  long long x, y;
  cin >> x >> y;

  int ans = 0;
  while (y >= x) {
    x *= 2;
    ans++;
  }

  cout << ans << endl;
  return 0;
}