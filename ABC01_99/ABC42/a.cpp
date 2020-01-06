#include <iostream>
#include <string>
using namespace std;

int main() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  int count5 = 0, count7 = 0;
  for (int i = 0; i < 3; i++) {
    if (a[i] == 5) count5++;
    if (a[i] == 7) count7++;
  }

  if (count5 == 2 && count7 == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}