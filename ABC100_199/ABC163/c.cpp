#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N, 0);
  for (int i = 1; i < N; i++) {
    int a;
    scanf("%d", &a);
    A[a - 1]++;
  }

  for (int i = 0; i < A.size(); i++) printf("%d\n", A[i]);

  return 0;
}