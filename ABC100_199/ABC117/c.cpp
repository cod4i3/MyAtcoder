#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> X(M), dist;
  for (int i = 0; i < M; i++) cin >> X[i];
  if (M <= N) {
    cout << 0 << endl;
    return 0;
  }
  sort(X.begin(), X.end());
  for (int i = 1; i < M; i++) {
    dist.push_back(X[i] - X[i - 1]);
  }
  sort(dist.begin(), dist.end());
  for (int i = 0; i < N - 1; i++) {
    dist.pop_back();
  }

  cout << accumulate(dist.begin(), dist.end(), 0) << endl;
}