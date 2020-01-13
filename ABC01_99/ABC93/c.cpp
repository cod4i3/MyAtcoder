#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> n(3);
  cin >> n[0] >> n[1] >> n[2];
  sort(n.begin(), n.end());
  int cnt = 0;
  while (n[0] != n[1] || n[1] != n[2]) {
    ++cnt;
    if (n[2] - n[0] > 1)
      n[0] += 2;
    else
      n[0] += 1, n[1] += 1;
    sort(n.begin(), n.end());
  }
  cout << cnt << endl;
  return 0;
}