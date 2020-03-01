#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll ans1 = ll(max_element(a.begin(), a.end()) - a.begin());
  ll half = a[ans1] / 2;
  ll ans2 = 0;
  if (ans1 == 0) ans2 = 1;
  for (int i = 0; i < n; i++) {
    if (abs(half - a[i]) < abs(half - a[ans2]) && i != ans1)
      ans2 = i;
    else if (abs(half + 1 - a[i]) < abs(half + 1 - a[ans2]) && n % 2 == 1 &&
             i != ans1)
      ans2 = i;
  }

  cout << a[ans1] << ' ' << a[ans2] << endl;
}