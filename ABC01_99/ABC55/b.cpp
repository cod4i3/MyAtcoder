#include <iostream>
using namespace std;
typedef long long ll;

ll Factorial(ll x) {
  if (x == 1 || x == 0)
    return 1;
  else
    return x * Factorial(x - 1) % 1000000007;
}

int main() {
  ll N;
  cin >> N;
  cout << Factorial(N) << endl;
}