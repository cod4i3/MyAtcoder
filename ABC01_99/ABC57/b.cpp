#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<pair<int, int> > a, b;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back(make_pair(x, y));
  }

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    b.push_back(make_pair(x, y));
  }

  vector<vector<pair<int, int> > > manhat(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int dis = abs(a[i].first - b[j].first) + abs(a[i].second - b[j].second);
      manhat[i].push_back(make_pair(dis, j + 1));
    }
  }

  for (int i = 0; i < N; i++) sort(manhat[i].begin(), manhat[i].end());

  for (int i = 0; i < N; i++) cout << manhat[i][0].second << endl;
}