#include <algorithm>
#include <iostream>
using namespace std;
#define MAX_N 100010

int main() {
  int N;
  cin >> N;
  int t[MAX_N];
  int a[MAX_N];
  int b[MAX_N];
  for (int i = 1; i <= N; i++) cin >> t[i] >> a[i] >> b[i];

  for (int i = 0; i < N; i++) {
    int T = t[i + 1] - t[i];
    int D = abs(a[i + 1] - a[i]) + abs(b[i + 1] - b[i]);
    if (T < D || T % 2 != D % 2) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
