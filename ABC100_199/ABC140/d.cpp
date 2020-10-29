#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  string str;
  cin >> str;
  vector<pair<char, int>> S;
  for (int l = 0; l < N;) {
    int r = l + 1;
    for (; r < N && str[l] == str[r]; r++)
      ;
    S.push_back({str[l], r - l});
    l = r;
  }

  int sum = 0;
  for (int i = 1; i < N; i++) {
    if (str[i] == str[i - 1]) sum++;
  }

  int limit = S.size() / 2;
  if (limit <= K) {
    cout << N - 1 << endl;
    return 0;
  } else {
    sum += 2 * K;
  }

  cout << sum << endl;
  return 0;
}