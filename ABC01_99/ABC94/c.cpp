#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<int> y(N);
  vector<int> x;
  vector<int> l(N);
  for (int i = 0; i < N; i++) {
    int X;
    cin >> X;
    x.emplace_back(X);
    y[i] = x[i];
  }

  sort(y.begin(), y.end());

  for (int i = 0; i < N; i++) {
    auto l = lower_bound(y.begin(), y.end(), x[i]);
    size_t pos = distance(y.begin(), l);
    if (pos <= (N - 1) / 2)
      cout << y[(N - 1) / 2 + 1] << endl;
    else
      cout << y[(N - 1) / 2] << endl;
  }
  return 0;
}