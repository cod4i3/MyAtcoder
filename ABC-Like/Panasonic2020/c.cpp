#include <iostream>
#include <cmath>
using namespace std;
int main() {
  long double a, b, c;
  cin >> a >> b >> c;

  if (sqrt(c) > sqrt(a) + sqrt(b))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
