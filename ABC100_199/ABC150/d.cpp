#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;


ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

ll lcm_n(vector<ll> &numbers) {
  ll l;
  l = numbers[0];
  for (int i = 1; i < numbers.size(); i++) {
    l = lcm(l, numbers[i]);
  }
  return l;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> A;
  ll m = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  ll lcm = lcm_n(A);
  return 0;
}