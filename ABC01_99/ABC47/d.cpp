#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;

  int a[N];
  for (int i = 0; i < N; i++) cin >> a[i];

  int d = a[0];
  int profit = -1000000000;
  for (int i = 0; i < N; i++) {
    profit = max(profit, a[i] - d);
    d = min(d, a[i]);
  }

  int cost = 0;
  int u = -1000000000;
  d = a[0];
  for (int i = 0; i < N; i++) {
    u = max(u, a[i] - d);
    d = min(d, a[i]);
    if (profit == u) {
      cost++;
      u = -1000000000;
      if (i < N - 1) d = a[i + 1];
    }
  }

  cout << cost << endl;
  return 0;
}
