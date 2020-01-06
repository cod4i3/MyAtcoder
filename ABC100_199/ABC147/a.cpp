#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if ((a + b + c) > 21)
    cout << "bust" << endl;
  else
    cout << "win" << endl;
  return 0;
}