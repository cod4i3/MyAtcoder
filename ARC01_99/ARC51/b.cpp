#include <iostream>
using namespace std;
using ll = long long;
int main() {
  ll a = 0, b = 1, c = 0;
  int K;
  cin >> K;
  int cnt = 0;
  while (cnt != K) {
    a = b + c;
    c = b;
    b = a;
    cnt++;
  }
  a = b + c;
  if (K != 1)
    cout << a << " " << b << endl;
  else
    cout << 1 << " " << 1 << endl;
  return 0;
}