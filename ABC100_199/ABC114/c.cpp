#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
ll N;
ll ans;

void solve(string s) {
  if (stol(s) > N) return;
  if (count(all(s), '7') && count(all(s), '5') && count(all(s), '3')) ans += 1;
  solve(s + "7");
  solve(s + "5");
  solve(s + "3");
}

int main() {
  cin >> N;
  solve("3");
  solve("5");
  solve("7");
  cout << ans << endl;
  return 0;
}