#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> A(N);
  vector<pair<int, ll> > P;
  REP(i, N) cin >> A[i];
  REP(i, M) {
    int b;
    ll c;
    cin >> b >> c;
    P.push_back(make_pair(c, b));
  }

  sort(A.begin(), A.end());
  sort(P.begin(), P.end(), greater<ll>());
}