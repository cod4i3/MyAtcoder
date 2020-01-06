#include <iostream>
#include <queue>
using namespace std;

int main() {
  int N;
  cin >> N;
  float tax = 1.08;
  queue<int> ans;
  for (int i = 0; i <= 50000; i++) {
    int money = i * tax;
    if (money == N) {
      ans.push(i);
      break;
    }
  }
  if (ans.empty()) cout << ":(" << endl;

  while (!ans.empty()) {
    cout << ans.front() << endl;
    ans.pop();
  }

  return 0;
}