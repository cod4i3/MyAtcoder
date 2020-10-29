#include <iostream>
using namespace std;
typedef long long ll;
#define MAX 210000

int main() {
  ll N;
  ll A[MAX];
  ll sumA = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sumA += A[i];
  }

  ll halfA = 0;
  ll half = 1000000000000000000;
  for (int i = 0; i < N; i++) {
    halfA += A[i];
    if (sumA % 2 == 0) {
      if (abs(sumA / 2 - half) > abs(sumA / 2 - halfA))
        half = halfA;
      else
        half = half;
    } else if (sumA % 2 == 1) {
      if (abs(sumA / 2 - half) > abs((sumA / 2 + 1) - halfA))
        half = halfA;
      else
        half = half;
    }
  }

  ll ans = 0;

  if (half > sumA / 2) {
    ans = half - (sumA - half);
  } else if (half < sumA / 2) {
    ans = (sumA - half) - half;
  }

  cout << ans << endl;

  return 0;
}