#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> ans;
  for (int bit = 0; bit < 1 << N; bit++) {
    string str = "";
    if (N <= 4 && (1 << (N - 1)) & bit) continue;
    for (int n = 1; n <= 25; n++) {
      for (int i = 0; i < N; i++) {
        if (1 << i & bit)
          str.insert(str.begin(), char('a' + n));
        else
          str.insert(str.begin(), 'a');
      }
      if (str.length() == N) ans.emplace_back(str);
    }
  }

  sort(ans.begin(), ans.end());
  int num = 1;
  for (int i = 1; i <= N; i++) num *= i;
  for (int i = 0; i < num; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}