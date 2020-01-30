#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v(5);
  for (int i = 0; i < 5; i++) cin >> v[i];

  int ans = 1000;
  int cnt = 0;
  do {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
      if (i == 4) {
        sum += v[i];
        break;
      }
      sum += v[i] / 10 * 10;
      v[i] % 10 ? sum += 10 : sum;
    }

    ans = min(ans, sum);
  } while (next_permutation(v.begin(), v.end()));

  cout << ans << endl;
  return 0;
}