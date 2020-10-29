#include <iostream>
using namespace std;

int main() {
  int N, ans = 0;
  cin >> N;

  for (int i = 1; i < N; i++) {
    for (int j = 1; j * j <= N - i; j++) {
      if ((N - i) % j == 0) {
         if(j * j == (N - i)) ans += 1;
         else ans += 2;
      }
    }
  }

  cout << ans << endl;
  return 0;
}