#include <iostream>
using namespace std;

int main() {
  int a[3], cnt = 1;
  cin >> a[0] >> a[1] >> a[2];
  if (a[1] != a[0]) cnt++;
  if (a[2] != a[1] && a[2] != a[0]) cnt++;

  cout << cnt << endl;
  return 0;
}