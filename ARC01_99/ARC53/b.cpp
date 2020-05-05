#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
// int odd_cnt[100005], even_cnt[100005];

int main() {
  string S;
  cin >> S;
  map<char, int> mp;
  for (int i = 0; i < S.length(); i++) {
    if (mp.count(S[i]) == 0)
      mp.insert(make_pair(S[i], 1));
    else
      mp[S[i]]++;
  }

  priority_queue<int, vector<int>, greater<int> > odd_que;
  priority_queue<int> even_que;
  int flag = 0;
  for (auto it : mp) {
    if (it.second % 2) {
      odd_que.push(1);
      even_que.push(it.second - 1);
      flag += 1;
    } else
      even_que.push(it.second);
  }

  int ans = 1;
  if (flag < 2) {
    cout << S.length() << endl;
    return 0;
  }

  while (!even_que.empty()) {
    int e = even_que.top();
    even_que.pop();
    while (e != 0) {
      int o = odd_que.top();
      odd_que.pop();
      e -= 2;
      o += 2;
      odd_que.push(o);
      if (e <= 0) break;
    }
  }

  cout << odd_que.top() << endl;
  return 0;
}