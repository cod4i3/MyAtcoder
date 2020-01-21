#include <iostream>
using namespace std;
#define MAX_M 1000000

bool f[MAX_M];

int main() {
  int s;
  cin >> s;
  int ans = 1;
  while (true) {
    if (f[s]) break;
    f[s] = true;
    ans++;
    if (s % 2)
      s = 3 * s + 1;
    else
      s /= 2;
  }
  cout << ans << endl;
}