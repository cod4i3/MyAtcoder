#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  string S;
  cin >> S;
  stack<long long int> n;
  long long int cur = S[0] - '0';
  n.push(cur);

  for (int i = 1; i < S.length(); i += 2) {
    if (S[i] == '+')
      n.push(S[i + 1] - '0');
    else {
      cur = n.top() * (S[i + 1] - '0');
      n.pop();
      n.push(cur);
    }
  }

  long long int ans = 0;
  while (!n.empty()) {
    cur = n.top();
    if (cur > 0) ans++;
    n.pop();
  }

  cout << ans << endl;
  return 0;
}