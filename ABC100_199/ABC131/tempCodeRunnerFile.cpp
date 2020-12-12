#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int M = ((N - 1) * (N - 2)) / 2;

  vector<pair<int, int>> ans;
  for (int i = 0; i < N - 1; i++) {
    ans.emplace_back(make_pair(1, i + 2));
  }

  for (int i = 2; i < N ; i++) {
    for (int j = i + 1; j <= N; j++) {
      cout << i << " " << j << endl;
      ans.emplace_back(make_pair(i, j));
    }
  }

  cout << (N - 1) + M - K << endl;
  for (int i = 0; i < (N - 1) + M - K; i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}