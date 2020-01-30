#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  ll GCD = gcd(A[0], A[1]);
  for (int i = 2; i < N; i++) {
    GCD = gcd(GCD, A[i]);
  }

  cout << GCD << endl;
  return 0;
}