#include <iostream>
using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;

  ll h, n, w ;
  bool flag = false;
  for (h = 1; h <= 3500; h++) {
    for (n = 1; n <= 3500; n++) {
      if (4 * h * n - N * n - N * h <= 0) continue;
      if (N * h * n % (4 * h * n - N * n - N * h) == 0) {
          w = N * h * n / (4 * h * n - N * n - N * h);
          flag = true;
      }
      if (flag) break;
    }
    if (flag) break;
  }

  cout << h << " " << n << " " << w << endl;
  return 0;
}