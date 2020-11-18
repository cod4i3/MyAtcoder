#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> p(N);
  for(int i=0; i<N; i++) cin >> p[i];

  vector<bool> ans(210000, true);
  int cur = 0;
  for (int i = 0; i < N; i++) {
    ans[p[i]] = false;
    for (; cur <= 210000; cur++) {
      if (ans[cur]) {
        cout << cur << endl;
        break;
      }
    }
  }
  return 0;
}