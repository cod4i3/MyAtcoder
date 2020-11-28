#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<bool> seen(N, false);
  vector<int> b(N);
  for (int i = 0; i < N; i++) {
    cin >> b[i];
    if (b[i] > i + 1) {
      cout << -1 << endl;
      return 0;
    }
  }

  vector<int> ans;
  for (int i = 0; i < N; i++) {
    int cnt = 0, res = 0;
    for (int j = 0; j < N; j++) {
      if (seen[j]) continue;
      cnt++;
      if (cnt == b[j]) res = j;
    }
    seen[res] = true;
    ans.emplace_back(b[res]);
  }

  reverse(ans.begin(), ans.end());
  for (int i = 0; i < N; i++) cout << ans[i] << endl;
  return 0;
}