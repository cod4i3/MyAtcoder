// memoを見ないで回答、 2020/2/7

#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

ll pow3(ll N) { return N * N * N; }

int main() {
  int N, K;
  cin >> N >> K;

  if (K % 2 == 0) cout << pow3(N / K) + pow3((N + K / 2) / K) << endl;
  if (K % 2 == 1) cout << pow3(N / K) << endl;
  return 0;
}