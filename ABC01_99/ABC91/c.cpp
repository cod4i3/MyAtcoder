#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 105
bool seen[MAX_N];

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return a.first < b.first;
  }
}

int main() {
  int N;
  cin >> N;
  vector<pair<int, int> > p, q;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    p.push_back(make_pair(a, b));
  }

  for (int i = 0; i < N; i++) {
    int c, d;
    cin >> c >> d;
    q.push_back(make_pair(c, d));
  }

  sort(p.begin(), p.end());
  sort(q.begin(), q.end());

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (seen[i]) break;
      if (seen[j]) continue;
      if (p[i].first < q[j].first && p[i].second < q[j].second) {
        ans++;
        seen[j] = true, seen[i] = true;
      }
    }
  }

  cout << ans << endl;
  return 0;
}