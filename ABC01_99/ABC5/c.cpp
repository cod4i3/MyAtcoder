#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void no() { cout << "no" << endl; }
void yes() { cout << "yes" << endl; }
int main() {
  int T, N, M;
  cin >> T >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  cin >> M;
  vector<int> B(M);
  for (int i = 0; i < M; i++) cin >> B[i];
  if (M > N) {
    no();
    return 0;
  }

  queue<int> t;
  queue<int> c;
  for (int i = 0; i < N; i++) t.push(A[i]);
  for (int i = 0; i < M; i++) c.push(B[i]);

  while (!c.empty()) {
    if (t.empty()) {
      no();
      return 0;
    }
    if (c.front() - t.front() <= T && c.front() - t.front() >= 0) {
      t.pop();
      c.pop();
    } else {
      t.pop();
    }
  }

  yes();
  return 0;
}
