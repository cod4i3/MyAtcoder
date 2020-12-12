#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> P;
  for (int i = 3; i <= 55555; i++) {
    bool flag = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
          flag = false;
          break;
      }
    }
    if (flag && i % 5 == 1) P.emplace_back(i);
    if(int(P.size()) == N) break;
  }

  for(int i=0; i<N; i++) cout << P[i] << " ";
  cout << endl;
}