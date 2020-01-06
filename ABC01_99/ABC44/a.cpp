#include <iostream>
using namespace std;

int main() {
  int N, K, X, Y;
  cin >> N >> K >> X >> Y;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (i < K)
      ans += X;
    else
      ans += Y;
  }

  cout << ans << endl;
  return 0;
}