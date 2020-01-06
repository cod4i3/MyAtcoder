#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll X, Y;
  cin >> X >> Y;

  if (Y < X / 2 || Y > 2 * X) {
    cout << 0 << endl;
  }

  if ((2 * X - Y) % 3 != 0) {
    cout << 0 << endl;
  }

  
}