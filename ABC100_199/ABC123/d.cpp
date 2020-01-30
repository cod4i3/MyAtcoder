#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  int x, y, z;
  ll k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);
  for (int i = 0; i < x; i++) cin >> a[i];
  for (int i = 0; i < y; i++) cin >> b[i];
  for (int i = 0; i < z; i++) cin >> c[i];
  return 0;
}