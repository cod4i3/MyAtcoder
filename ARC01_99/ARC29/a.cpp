#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> t(N);
  for (int i = 0; i < N; i++) cin >> t[i];
  if (N == 1) {
    cout << t[0] << endl;
    return 0;
  }

  int ans, one = 0, two = 0;
  sort(t.begin(), t.end(), greater<int>());
  for (int i = 0; i < t.size(); i++) {
    if (one > two) swap(one, two);
    one += t[i];
  }

  cout << max(one, two) << endl;
  return 0;
}