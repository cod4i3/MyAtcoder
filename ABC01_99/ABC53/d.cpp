#include <iostream>
#include <set>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> st;

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    if (st.count(n) > 0)
      cnt++;
    else
      st.insert(n);
  }

  int ans = st.size();
  if (cnt % 2 == 1) --ans;
  cout << ans << endl;
  return 0;
}