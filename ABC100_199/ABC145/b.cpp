#include <string.h>
#include <iostream>
using namespace std;

int main() {
  int N;
  string r;
  cin >> N >> r;
  if (N % 2 == 1) {
    cout << "No" << endl;
    return 0;
  }

  for (int i = 0; i < N / 2; i++) {
    if (r[i] != r[N / 2 + i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}