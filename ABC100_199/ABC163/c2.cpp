#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N, 0);
  for (int i = 1; i < N; i++) {
    int a;
    cin >> a;
    A[a - 1]++;
  }

  for (int i = 0; i < A.size(); i++) cout << A[i] << endl;

  return 0;
}
