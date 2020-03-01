#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int t[N];
  for (int i = 0; i < N; i++) cin >> t[i];
  int one, two;
  int ans = 10000;
  for (int bit = 0; bit < (1 << N); bit++) {
    one = 0, two = 0;
    for (int i = 0; i < N; i++) {
      if (((1 << i) & bit) == 0) {
        two += t[i];
      } else
        one += t[i];
    }
    ans = min(ans, max(one, two));
  }

  cout << ans << endl;
  return 0;
}