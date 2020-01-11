#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 105000

int main() {
  int N;
  cin >> N;
  vector<int> A(MAX_N, 0);
  for (int i = 1; i <= N; i++) cin >> A[i];
  vector<int> dis(MAX_N, 0);
  vector<int> S(MAX_N, 0);

  int sum = 0;
  for (int i = 1; i <= N + 1; i++) sum += abs(A[i] - A[i - 1]);
  for (int i = 1; i <= N; i++) {
    S[i] = abs(A[i - 1] - A[i + 1]) -
           (abs(A[i - 1] - A[i]) + abs(A[i] - A[i + 1]));
  }

  for (int i = 1; i <= N; i++) {
    cout << sum + S[i] << endl;
  }

  return 0;
}