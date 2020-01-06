#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;
  string str;
  vector<string> v;
  for (int i = 0; i < N; i++) {
    cin >> str;
    v.push_back(str);
  }

  sort(v.begin(), v.end());
  string ans;

  for (int i = 0; i < N; i++) {
    ans += v[i];
  }

  cout << ans << endl;
  return 0;
}