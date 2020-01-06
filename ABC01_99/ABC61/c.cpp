#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<pair<int, int> > v;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }

  sort(v.begin(), v.end());
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum += v[i].second;
    if (sum >= K) {
      cout << v[i].first << endl;
      break;
    }
  }

  return 0;
}