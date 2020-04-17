#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long int;
int main() {
  int N;
  cin >> N;
  vector<ll> a(N), c;

  for (int i = 0; i < N; i++) {
    cin >> a[i];
    c.emplace_back(a[i]);
  }

  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());

  for (int i = 0; i < N; i++) {
    auto itr = lower_bound(c.begin(), c.end(), a[i]);
    cout << distance(c.begin(), itr) << endl;
  }

  return 0;
}
