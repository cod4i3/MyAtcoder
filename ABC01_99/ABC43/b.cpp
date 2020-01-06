#include <iostream>
#include <vector>
using namespace std;

int main() {
  string str;
  vector<string> ans;
  cin >> str;

  for (int i = 0; i < str.length(); i++) {
    if (str.at(i) == '0') {
      ans.push_back("0");
    } else if (str.at(i) == '1') {
      ans.push_back("1");
    } else if (str.at(i) == 'B') {
      if (!ans.empty()) ans.pop_back();
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
  }
  cout << endl;
  return 0;
}