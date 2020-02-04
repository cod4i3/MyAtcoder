#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll gcd_n(vector<ll> &numbers) {
  ll GCD;
  GCD = numbers[0];
  for (int i = 1; i < numbers.size(); i++) {
    GCD = gcd(GCD, numbers[i]);
  }
  return GCD;
}
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  ll GCD_N = gcd_n(A);

  if (GCD_N == 1) {
    for (int i = 0; i < N - 2; i++) {
      if (gcd(A[i], A[i + 1]) == 1 && gcd(A[i + 1], A[i + 2]) == 1) {
        A[i + 1] = A[i];
        break;
      } else if (gcd(A[i], A[i + 1]) == 1) {
        A[i] = A[i + 1];
        break;
      } else {
        A[i + 2] = A[i];
        break;
      }
    }
  } else {
    ll GCD = gcd(A[0], A[1]);
    for (int i = 1; i < N; i++) {
      if (GCD_N == gcd(GCD, A[i])) {
        A[i] = *max_element(A.begin(), A.end());
        break;
      }
      GCD = gcd(GCD, A[i]);
    }
  }

  cout << gcd_n(A) << endl;
  return 0;
}