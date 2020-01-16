#include <iostream>
using namespace std;

int main() {
  int N, sum = 0, cntp = 0,cntn = 0, zero=0;
  cin >> N;
  int A[N];
  int p = 0, n;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[i] -= i;
    sum += A[i];
    if (A[i]) {
      cntp++;
      p += A[i];
    }else if(A[i] == 0)
      zero++;
  }

  n = p - sum;
  cntn = N - cntp - zero;
  int ans = 0;
  int b = sum / abs(cntn - cntp);
  for (int i = 0; i < N; i++) {
  }
}