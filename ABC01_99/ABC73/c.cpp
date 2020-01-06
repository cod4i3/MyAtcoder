#include <iostream>
#include <set>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> a;
  REP(i, N) {
    int A;
    cin >> A;
    if (!a.count(A))
      a.insert(A);
    else
      a.erase(A);
  }

  cout << a.size() << endl;
  return 0;
}