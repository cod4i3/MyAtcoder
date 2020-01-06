#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
string s;
ll sum = 0;

void dfs(ll tmp, ll cnt, ll cur) {
  // +が入る場合、入らない場合
  if (cur == s.size()) {
    if (tmp == 0) sum += cnt;
    return;
  }
  dfs(tmp * 10 + s[cur] - '0', cnt, cur + 1);
  dfs(0, tmp * 10 + s[cur] - '0' + cnt, cur + 1);
}

int main() {
  cin >> s;
  dfs(0, 0, 0);
  cout << sum << endl;
  return 0;
}
