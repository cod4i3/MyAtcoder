#include <iostream>
using namespace std;
typedef long long ll;

ll sum(ll x) {
  if (x == 0)
    return 0;
  else if (x == 1)
    return 1;
  else
    return x + sum(x - 1);
}

int main() {
  int x;
  cin >> x;
  int t = 0;
  while (sum(t) < x) t++;
  cout << t << endl;
  return 0;
}