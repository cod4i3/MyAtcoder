#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  if (A >= 10 || B >= 10) {
    cout << -1 << endl;
    return 0;
  } else {
    cout << A * B << endl;
  }

  return 0;
}