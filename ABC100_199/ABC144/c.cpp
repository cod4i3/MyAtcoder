#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;
  ll x, y = 0;
  for (int i = 1; i <= sqrt(N); i++) {
    if (N % i == 0) {
      x = i;
      y = N / i;
    }
  }

  if (y == 0) {
    cout << N - 1 << endl;
  } else {
    cout << x + y - 2 << endl;
  }

  return 0;
}