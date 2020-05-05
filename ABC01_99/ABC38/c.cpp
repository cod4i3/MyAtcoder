#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];

  int r = 0, l = 0, s = 0;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    long long sum = 1;
    for (int j = i + 1; j < N; j++) {
      if (a[j] > a[j - 1]) {
        sum++;
        if (j == N - 1) {
          i = j - 1;
          break;
        }
      } else {
        i = j - 1;
        break;
      }
    }
    ans += (sum * (sum - 1)) / 2;
  }
  ans += N;
  cout << ans << endl;

  return 0;
}