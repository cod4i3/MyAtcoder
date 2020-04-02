#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  int Q;
  cin >> str >> Q;
  deque<char> deq;
  for (auto c : str) deq.push_back(c);
  bool rev = false;

  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 1) rev ^= 1;

    if (t == 2) {
      int f;
      char c;
      cin >> f >> c;

      if ((f - 1) ^ rev)
        deq.push_back(c);
      else
        deq.push_front(c);
    }
  }

  if (!rev) {
    for (auto it = deq.begin(); it != deq.end(); ++it) cout << *it;
  } else if (rev == 1) {
    for (auto it = deq.rbegin(); it != deq.rend(); ++it) cout << *it;
  }
  cout << '\n';

  return 0;
}
