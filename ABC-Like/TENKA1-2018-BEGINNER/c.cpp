#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  sort(A.begin(), A.end());
  ll resl = A[0], resr = A[N - 1];
  deque<ll> dq;

  for (int i = 0; i < N; i++) dq.push_back(A[i]);

  ll ans = 0, res = dq.back();
  dq.pop_back();
  for (int i = 1; i < N - 1; i++) {
    if (i % 2) {
      ans += abs(res - dq.front());
      res = dq.front();
      dq.pop_front();
    } else {
      ans += abs(res - dq.back());
      res = dq.back();
      dq.pop_back();
    }
  }

  ans += max(abs(dq.front() - resl), abs(dq.front() - resr));

  cout << ans << endl;
  return 0;
}