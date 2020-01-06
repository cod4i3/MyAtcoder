#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> cnt(100000, 0);
  REP(i, N) {
    int A;
    cin >> A;
    cnt[A]++;
  }

  int num = 0;
  int ans = 0;
  REP(i, cnt.size()) {
    num = 0;
    num += cnt[i];
    if (cnt[i - 1]) num += cnt[i - 1];
    if (cnt[i + 1]) num += cnt[i + 1];
    ans = max(ans, num);
  }

  cout << ans << endl;
  return 0;
}