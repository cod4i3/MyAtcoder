#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;

  vector<ll> A(N);
  ll sum = 0;
  FOR(i, N) {
    cin >> A[i];
    sum += A[i];
  }

  vector<ll> D(N);
}