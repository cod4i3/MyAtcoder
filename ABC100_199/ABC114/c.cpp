#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long ll;
ll N;

// cur = 現在 use = 753のどれを使ったか
// フラグをintで実装するのは無理、バイナリを駆使しよう
void dfs(ll cur, ll use, long long &ans) {
  if(cur > N) return;
  if(use == 0b111) ans++;

  dfs(cur * 10 + 7, use | 0b001, ans);
  dfs(cur * 10 + 5, use | 0b010, ans);
  dfs(cur * 10 + 3, use | 0b100, ans);

}

int main() {
  cin >> N;
  ll res = 0;
  dfs(0, 0, res);
  cout << res << endl;
}