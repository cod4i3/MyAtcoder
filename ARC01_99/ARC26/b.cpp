#include <cmath>
#include <iostream>
using namespace std;

int main() {
  long long N;
  cin >> N;

  long long sum = -N;
  for (long long i = 1; i * i <= N; i++) {
    if (N % i == 0) sum += i + (N / i);
    if (i * i == N) sum -= i;
  }

  if (sum == N)
    cout << "Perfect" << endl;
  else if (sum > N)
    cout << "Abundant" << endl;
  else
    cout << "Deficient" << endl;
  return 0;
}