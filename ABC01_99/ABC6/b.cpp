#include <iostream>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int a[n + 10];
  a[1] = a[2] = 0;
  a[3] = a[4] = 1;
  for (int i = 4; i < n + 2; i++) {
    a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    a[i] %= 10007;
  }
  cout << a[n] << endl;
  return 0;
}