#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll N;
vector<bool> seen(1100000, false);

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll gcd_n(vector<ll> &numbers) {
  ll GCD;
  GCD = numbers[0];
  for (int i = 1; i < numbers.size(); i++) {
    GCD = gcd(GCD, numbers[i]);
  }
  return GCD;
}

bool prime_factor(ll n) {
  vector<pair<ll, int>> ret;

  for (ll i = 2; i * i <= n; i++) {
    if (n % i != 0) {
      continue;
    }
    int exp_v = 0;
    while (n % i == 0) {
      exp_v++;
      n /= i;
    }
    ret.emplace_back(make_pair(i, exp_v));
  }

  if (n != 1) {
    ret.emplace_back(make_pair(n, 1));
  }

  for (int i = 0; i < ret.size(); i++) {
    if (seen[ret[i].first])
      return false;
    else
      seen[ret[i].first] = true;
  }
  return true;
}

int main() {
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  bool flag = true;
  for (int i = 0; i < N; i++) {
    if (!prime_factor(A[i])) {
      flag = false;
    }
  }

  if (gcd_n(A) == 1) {
    if (!flag)
      cout << "setwise coprime" << endl;
    else
      cout << "pairwise coprime" << endl;
    return 0;
  };

  cout << "not coprime" << endl;
  return 0;
}