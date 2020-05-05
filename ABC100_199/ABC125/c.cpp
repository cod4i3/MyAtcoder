#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), L(N), R(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  L[0] = A[0];
  R[N - 1] = A[N - 1];
  for (int i = 1; i < N; i++) L[i] = gcd(L[i - 1], A[i]);
  for (int i = N - 2; i >= 1; i--) R[i] = gcd(R[i + 1], A[i]);

  vector<ll> ans(N);
  ans[0] = R[1], ans[N - 1] = L[N - 2];
  for (int i = 1; i < N - 1; i++) {
    ans[i] = gcd(L[i - 1], R[i + 1]);
  }

  cout << *max_element(ans.begin(), ans.end()) << endl;
  return 0;
}
