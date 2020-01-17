#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
  int n;
  cin >> n;
  vector<int> v(n), odd(110000, 0), even(110000, 0);
  int cnt = 0;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i += 2) {
    odd[v[i]] += 1;
    even[v[i + 1]] += 1;
  }
  auto maxO = max_element(all(odd));
  auto maxE = max_element(all(even));
  bool sameNum = false;
  if (distance(odd.begin(), maxO) == distance(even.begin(), maxE))
    sameNum = true;

  sort(all(odd), greater<int>());
  sort(all(even), greater<int>());

  if (sameNum) {
    cout << n - odd[0] - max(odd[1], even[1]);
    return 0;
  }
  cout << n - odd[0] - even[0] << endl;
  return 0;
}