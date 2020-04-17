//#pragma GCC optimize("Ofast")
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<string> l;

void dfs(string c, int n) {
  if (c.length() == n) {
    l.emplace_back(c);
    return;
  }
  dfs(c + "a", n);
  dfs(c + "b", n);
  dfs(c + "c", n);
  return;
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  int N;
  cin >> N;
  dfs("a", N);
  dfs("b", N);
  dfs("c", N);
  for (int i = 0; i < l.size(); i++) cout << l[i] << endl;

  return 0;
}