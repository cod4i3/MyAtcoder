#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> h(N);
  for (int i = 0; i < N; i++) cin >> h[i];

  vector<int> w(N, 0), e(N, 0);
  for (int i = 0; i < N - 1; i++) {
    if (h[i + 1] > h[i]) w[i + 1] = w[i] + 1;
  }

  for (int i = N - 1; i >= 1; i--) {
    if (h[i - 1] > h[i]) e[i - 1] = e[i] + 1;
  }


  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, w[i] + e[i] + 1);
  }

  cout << ans << endl;
  return 0;
}