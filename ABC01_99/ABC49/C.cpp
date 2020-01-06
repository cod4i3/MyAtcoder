#include <iostream>
#include <string>
using namespace std;

// dream, dreamer, erase, eraser
// 後ろ3文字に注目する
int main() {
  string str;
  cin >> str;

  while (!str.empty()) {
    if (str.size() < 5) {
      cout << "NO" << endl;
      return 0;
    }

    string s = str.substr(str.size() - 3);

    if (s == "eam") {
      if (str.substr(str.size() - 5) == "dream")
        str.erase(str.size() - 5, 5);
      else {
        cout << "NO" << endl;
        return 0;
      }
    } else if (s == "mer") {
      if (str.size() < 7) {
        cout << "NO" << endl;
        break;
      }
      if (str.substr(str.size() - 7) == "dreamer")
        str.erase(str.size() - 7, 7);
      else {
        cout << "NO" << endl;
        return 0;
      }
    } else if (s == "ase") {
      if (str.substr(str.size() - 5) == "erase")
        str.erase(str.size() - 5, 5);
      else {
        cout << "NO" << endl;
        return 0;
      }
    } else if (s == "ser") {
      if (str.size() < 6) {
        cout << "NO" << endl;
        break;
      }
      if (str.substr(str.size() - 6) == "eraser")
        str.erase(str.size() - 6, 6);
      else {
        cout << "NO" << endl;
        return 0;
      }
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}