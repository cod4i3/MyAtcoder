#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define FOR(i, n) for (int i = 1; i < (int)(n + 1); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int gcd_n(vector<int> &numbers) {
  int GCD;
  GCD = numbers[0];
  for (int i = 1; i < numbers.size(); i++) {
    GCD = gcd(GCD, numbers[i]);
  }
  return GCD;
}

int main() {
  int K;
  cin >> K;
  vector<int> num(3);
  ll sum = 0;
  FOR(a, K) {
    FOR(b, K) {
      FOR(c, K) {
        num[0] = a;
        num[1] = b;
        num[2] = c;
        sum += gcd_n(num);
      }
    }
  }
  cout << sum << endl;
  return 0;
}