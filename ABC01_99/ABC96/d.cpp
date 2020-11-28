#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> P;
  for (int i = 2; i <= 55555; i++) {
    bool flag = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
          flag = false;
          break;
      }
    }
    if (flag) P.emplace_back(i);
  }

  
  cout << endl;
}