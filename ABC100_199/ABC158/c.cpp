#include <iostream>
using namespace std;

int main() {
  double A, B;
  cin >> A >> B;
  int ans = -1;
  for (int i = 1; i <= 100; i++) {
    if ((i * 0.08) / 1 == A && (i * 0.1) / 1 == B) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}