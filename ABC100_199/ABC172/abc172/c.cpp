#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
  ll N, M, K;
  cin >> N >> M >> K;

  vector<ll> A(N), B(M);
  vector<ll> sumA(N), sumB(M);
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<M; i++) cin >> B[i];
  sumA[0] = A[0];
  sumB[0] = B[0];
  for(int i=1; i<N; i++) sumA[i] = A[i] + sumA[i-1];
  for(int i=1; i<M; i++) sumB[i] = B[i] + sumB[i-1];

  ll ans = 0;
  for(int i=0; i<N; i++){
      if(sumA[i] > K) break;
      ll res = upper_bound(sumB.begin(), sumB.end(), K - sumA[i]) - sumB.begin();
      ans = max(ans, i + res + 1);
  }

  for(int i=0; i<M; i++){
      if(sumB[i] > K) break;
      ll res = upper_bound(sumA.begin(), sumA.end(), K - sumB[i]) - sumA.begin();
      ans = max(ans, i + res + 1);
  }

  cout << ans << endl;
  return 0;
}