#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N), B(N), S(N);
  ll sum = 0;
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
  for (int i = 0; i < N; i++) {
    sum += A[i];
    S[i] = A[i] * 2 + B[i];
  }
  sort(S.begin(), S.end(), greater<ll>());

  ll res = 0, cnt = 0;
  for (int i = 0; i < N; i++) {
    res += S[i];
    if (res > sum) {
      cnt = i + 1;
      break;
    }
  }
  cout << cnt << endl;
  return 0;
}