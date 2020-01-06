#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> d(k);
  for (int i = 0; i < k; i++) {
    cin >> d[i];
  }

  for (int ans = n; ans < 100000; ans++) {
    int tmp = ans;
    vector<int> v;
    while (tmp != 0) {
      v.push_back(tmp % 10);
      tmp /= 10;
    }

    bool flag = true;
    for (int j = 0; j < k; j++) {
      if (count(v.begin(), v.end(), d[j])) flag = false;
    }

    if (flag) {
      cout << ans << endl;
      break;
    }
  }

  return 0;
}