#include <deque>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  deque<ll> Q;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    if (i % 2 == 1)
      Q.push_back(a);
    else
      Q.push_front(a);
  }

  if (n % 2 == 0) {
    for (int i = Q.size() - 1; i >= 0; i--) {
      cout << Q.at(i) << ' ';
    }
  } else {
    for (int i = 0; i < Q.size(); i++) {
      cout << Q.at(i) << ' ';
    }
  }
  cout << endl;
  return 0;
}