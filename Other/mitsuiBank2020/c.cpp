#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;

  // between a and b, you can buy
  int a = x / 100;
  if (a * 105 < x)
    cout << 0 << endl;
  else
    cout << 1 << endl;
  return 0;
}