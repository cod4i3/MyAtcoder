#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int A[4];
  for (int i = 3; i >= 0; i--) {
    A[i] = n % 10;
    n /= 10;
  }
  for (int bit = 0; bit < (1 << 3); bit++) {
    int ans = A[0];
    (bit & (1 << 2)) ? ans += A[1] : ans -= A[1];
    (bit & (1 << 1)) ? ans += A[2] : ans -= A[2];
    (bit & (1 << 0)) ? ans += A[3] : ans -= A[3];
    if (ans == 7) {
      cout << A[0];
      (bit & (1 << 2)) ? cout << '+' : cout << '-';
      cout << A[1];
      (bit & (1 << 1)) ? cout << '+' : cout << '-';
      cout << A[2];
      (bit & (1 << 0)) ? cout << '+' : cout << '-';
      cout << A[3] << '=' << 7 << endl;
      break;
    }
  }

  return 0;
}