#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<ll> A;
  REP(i, N) {
    int a;
    cin >> a;
    A.push_back(a);
  }
  sort(all(A));
  reverse(all(A));
  ll width = 0, length = 0;
  REP(i, N - 1) {
    if (A[i] == A[i + 1]) {
      if (width) {
        length = A[i];
        break;
      } else
        width = A[i];
      if (i == N - 1) break;
      i += 1;
    }
  }

  cout << width * length << endl;
  return 0;
}