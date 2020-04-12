#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
// 桁数、最上位桁
priority_queue<ll, vector<ll>, greater<ll> > que;

void dfs(ll c, ll num) {
  if (c > 10 || num > 3234566667) return;
  que.push(num);

  ll digit = num % 10;
  if (digit - 1 >= 0) dfs(c + 1, num * 10 + digit - 1);
  dfs(c + 1, num * 10 + digit);
  if (digit + 1 <= 9) dfs(c + 1, num * 10 + digit + 1);
}

int main() {
  int K;
  cin >> K;

  for (int i = 1; i <= 9; i++) dfs(0, i);
  for (int i = 0; i < K - 1; i++) que.pop();
  cout << que.top() << endl;
}