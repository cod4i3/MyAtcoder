#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> a(N * 3);
  for (int i = 0; i < N * 3; ++i) cin >> a[i];

  // 左から前処理
  vector<long long> S(N * 2 + 1, 0);
  priority_queue<long long, vector<long long>, greater<long long> > que1;
  for (int i = 0; i < N; ++i) {
    S[i + 1] = S[i] + a[i];
    que1.push(a[i]);
  }
  for (int i = N; i < N * 2; ++i) {
    long long mi = que1.top();
    if (a[i] > mi) {
      S[i + 1] = S[i] - mi + a[i];
      que1.pop();
      que1.push(a[i]);
    } else
      S[i + 1] = S[i];
  }

  // 右から前処理
  vector<long long> T(N * 2 + 1, 0);
  priority_queue<long long> que2;
  for (int i = 0; i < N; ++i) {
    T[i + 1] = T[i] + a[N * 3 - 1 - i];
    que2.push(a[N * 3 - 1 - i]);
  }
  for (int i = N; i < N * 2; ++i) {
    long long ma = que2.top();
    if (a[N * 3 - 1 - i] < ma) {
      T[i + 1] = T[i] - ma + a[N * 3 - 1 - i];
      que2.pop();
      que2.push(a[N * 3 - 1 - i]);
    } else
      T[i + 1] = T[i];
  }

  // 集計
  long long res = -(1LL << 60);
  for (int i = N; i <= N * 2; ++i) {
    res = max(res, S[i] - T[N * 3 - i]);
  }
  cout << res << endl;
}