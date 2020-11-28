#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> c(2 * N);
  for (int i = 0; i < N; i++) cin >> c[i];
  for (int i = 0; i < N; i++) c[i + N] = c[i];

  int cnt = 0, res = 0;
  bool flag = false;
  for (int i = 0; i < 2 * N - 1; i++) {
    if (c[i] == c[i + 1]) {
      cnt++;
      res = max(cnt, res);
    } else {
      cnt = 1;
      flag = true;
    }
  }

  
  if (!flag)
    cout << -1 << endl;
  else
    cout << ((res - 1) / 2) + 1 << endl;
  return 0;
}