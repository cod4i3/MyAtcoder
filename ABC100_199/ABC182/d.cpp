#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
 
  ll res = 0, ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i + 1; j++) {
        res += A[j];
        if(A[j] > 0) ans = max(res, ans);
    }
  }
  cout << ans << endl;
  return 0;
}