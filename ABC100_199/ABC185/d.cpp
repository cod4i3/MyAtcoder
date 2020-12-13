#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M);
  for (int i = 0; i < M; i++) cin >> A[i];
  sort(A.begin(), A.end());

  if(M >= N){
      cout << 0 << endl;
      return 0;
  }
  if(M == 0){
      cout << 1 << endl;
      return 0;
  }
  ll k = N;
  if(A[0] != 1) k = min(k, A[0] - 1);
  for (int i = 0; i < M - 1; i++) {
    k = min(k, max(ll(1), A[i + 1] - A[i] - 1));
  }

  ll ans = (A[0] - 1) / k;
  if ((A[0] - 1) % k) ans++;
  for (int i = 0; i < M - 1; i++) {
      ans += ((A[i + 1] - A[i]) - 1) / k;
      if(k != 1 && ((A[i + 1] - A[i]) - 1) % k) ans++;
  }
  ans += (N - A[M - 1]) / k;
  if(k != 1 && (N - A[M - 1]) % k) ans++;
  cout << ans << endl;
  return 0;
}