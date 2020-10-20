#define DECIMAL_DIG implementation - defined
#include <iostream>
using namespace std;

int main() {
  long double A, B;
  cin >> A >> B;
  cout << (long long)(A * B) << endl;
}