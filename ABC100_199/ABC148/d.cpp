#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
  int N;
  cin >> N;
  vector<int> A;
  REP(i, N) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  bool flag = false;
  int cur = 0;
  int cnt = 1;
  while (cur != N) {
    if (A[cur] == cnt)
      cnt++;
    else
      cur++;
  }

  if (cnt > 1)
    cout << N - cnt + 1 << endl;
  else
    cout << -1 << endl;
  return 0;
}