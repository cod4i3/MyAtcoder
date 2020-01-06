#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= 9; i++) {
    if (N / i < 10 && N % i == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}