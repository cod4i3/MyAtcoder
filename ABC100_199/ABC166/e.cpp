#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  vector<int> d(N);
  for (int i = 0; i < N; i++) d[i] = A[i] - A[0];

  for (int i = 0; i < N; i++) cout << d[i] << " ";
  cout << endl;

  return 0;
}