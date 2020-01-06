#include <iostream>
using namespace std;
typedef long long ll;
#define MAX_N 110000
#define MAX_M 110000
#define DIV 1000000007

int main() {
  ll N, M;
  cin >> N >> M;
  if (abs(N - M) >= 2) {
    cout << 0 << endl;
    return 0;
  }

  ll FacN[MAX_N], FacM[MAX_M];
  if (N < M) M = N + 1;
  FacN[0] = 1, FacN[1] = 1;
  FacM[0] = 1, FacM[1] = 1;
  for (ll i = 2; i <= N; i++) {
    FacN[i] = FacN[i - 1] * i % DIV;
    FacM[i] = FacM[i - 1] * i % DIV;
  }

  if (abs(N - M) == 1)
    cout << FacN[N] * FacM[M] % DIV << endl;
  else if (N == M)
    cout << ((FacN[N] * FacM[M] % DIV) * 2) % DIV << endl;

  return 0;
}