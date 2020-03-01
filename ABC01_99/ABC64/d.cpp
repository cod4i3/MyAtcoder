#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  string C;
  for (char s : S) {
    int back = C.size() - 1;
    if (C.empty()) {
      C.push_back(s);
      continue;
    } else {
      if (C[back] == '(' && s == ')')
        C.pop_back();
      else
        C.push_back(s);
    }
  }

  int l = 0, r = 0;
  for (int i = 0; i < C.size(); i++) {
    if (C[i] == '(')
      l++;
    else
      r++;
  }

  string left, right;
  for (int i = 0; i < r; i++) left.push_back('(');
  for (int i = 0; i < l; i++) right.push_back(')');
  cout << left + S + right << endl;
  return 0;
}