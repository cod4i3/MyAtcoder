#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_K 200100

int main() {
  int N, K, cur = 0;
  cin >> N >> K;

  vector<int> A(N, 0);
  vector<int> cnt(MAX_K, 0);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (!cnt[A[i]]) cur++;
    cnt[A[i]] += 1;
  }

  sort(cnt.begin(), cnt.end());
  int ans = 0, diff = cur - K;
  for (int i = 0; i < cnt.size(); i++) {
    if (diff <= 0) break;
    if (cnt[i]) {
      ans += cnt[i];
      diff--;
    }
  }
  cout << ans << endl;
  return 0;
}