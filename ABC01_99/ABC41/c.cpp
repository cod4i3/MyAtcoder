#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool greaterPair(pair<int, int> a, pair<int, int> b) {
  return a.first > b.first;
}

int main() {
  int N;
  cin >> N;
  vector<pair<int, int> > a;
  for (int i = 0; i < N; i++) {
    int tail;
    cin >> tail;
    a.push_back(make_pair(tail, i + 1));
  }

  sort(a.begin(), a.end(), greaterPair);
  for (int i = 0; i < N; i++) {
    cout << a[i].second << endl;
  }
}