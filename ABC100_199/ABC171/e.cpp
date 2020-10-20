#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0
#include <iostream>
#include <vector>
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  ll sum = 0;
  FOR(i, N) {
    cin >> a[i];
    sum ^= a[i];
  }

  FOR(i, N) { cout << (sum ^ a[i]) << " "; }
  cout << endl;
  return 0;
}
