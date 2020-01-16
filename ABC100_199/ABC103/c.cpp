#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++) cin >> a[i];
  long long ans = 0;
  for (int i = 1; i <= 3000; i++) {
    long long sum = 0;
    for (int j = 0; j < N; j++) sum += a[j] % i;
    ans = max(ans, sum);
  }

  cout << ans << endl;
  return 0;
}