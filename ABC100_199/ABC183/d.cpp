#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll N, W;
  cin >> N >> W;

  vector<vector<ll>> U(N, vector<ll>(3));

  int end = 0;
  for (int i = 0; i < N; i++) {
    ll S, P;
    int T;
    cin >> S >> T >> P;
    U[i] = {S, T, P};
    end = max(end, T);
  }

  ll ans = 0, res = 0;
  vector<ll> A(end + 10, 0);
  for (int i = 0; i < N; i++) {
    A[U[i][0]] += U[i][2];
    A[U[i][1]] -= U[i][2];
  }

  for (int i = 1; i <= end; i++) {
    A[i] += A[i - 1];
  }

  for (int i = 0; i <= end; i++) {
    if (A[i] > W) {
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
  return 0;
}