/*
    (B_1 + B_2) = 2A_1
    (B_2 + B_3) = 2A_2
    ...
    (B_N + B_1) = 2A_N

    i = oddのとき
    Σ(A_i) = 2(B_1) + (B_2) + (B_3)
    Σ(A) = Σ(B) より
    (B_1) = 2(A_i) - Σ(B)
    以下は上の方程式から
*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;

  vector<ll> A(N);
  ll sumA = 0;
  ll sumB = 0;
  FOR(i, N) {
    cin >> A[i];
    if (!(i % 2)) sumA += 2 * A[i];
    sumB += A[i];
  }
  vector<ll> B(N);
  B[0] = sumA - sumB;

  for (int i = 0; i < N - 1; i++) B[i + 1] = 2 * A[i] - B[i];
  FOR(i, N) cout << B[i] << " ";
  cout << endl;
}