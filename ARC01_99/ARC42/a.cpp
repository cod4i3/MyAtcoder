#include <iostream>
#include <stack>
using namespace std;

bool seen[200000];
int main() {
  int N, M;
  cin >> N >> M;
  stack<int> st;
  for (int i = 0; i < N; i++) {
    st.push(N - i);
  }
  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    st.push(a);
  }

  while (!st.empty()) {
    int s = st.top();
    if (!seen[s]) {
      seen[s] = true;
      cout << s << endl;
    }
    st.pop();
  }
  return 0;
}