#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int ans = 1000000000;
  for (int i = -100; i <= 100; i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
      sum += (a[j] - i) * (a[j] - i);
    }
    ans = min(sum, ans);
  }

  cout << ans << endl;
  return 0;
}
