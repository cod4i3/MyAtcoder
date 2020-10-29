#include <iostream>
using namespace std;

int main() {
  int X, Y;
  cin >> X >> Y;

  if (X == 1 && Y == 1) {
    cout << 1000000 << endl;
    return 0;
  }

  int ans = 0;
  if (X == 1)
    ans += 300000;
  else if (X == 2)
    ans += 200000;
  else if (X == 3)
    ans += 100000;

  if (Y == 1)
    ans += 300000;
  else if (Y == 2)
    ans += 200000;
  else if (Y == 3)
    ans += 100000;

  cout << ans << endl;
  return 0;
}