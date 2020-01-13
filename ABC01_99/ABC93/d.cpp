#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int Q;
  cin >> Q;
  vector<ll> A(Q), B(Q);
  for (int i = 0; i < Q; i++) cin >> A[i] >> B[i];
  for (int i = 0; i < Q; i++) {
    ll cur = A[i] * B[i];
    ll root = ll(sqrt(cur));
    // 平方数だった場合
    if ((root * root) == cur)
      cout << (root - 1) * (root - 1) << endl;
    else if (root * (root + 1) < cur)
      cout << 2 * root - 1 << endl;
    else
      cout << (root - 1) * 2 << endl;
  }
  return 0;
}