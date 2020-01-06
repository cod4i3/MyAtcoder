#include <iostream>
#include <vector>
using namespace std;

int main() {
  double N, A, B;
  cin >> N >> A >> B;
  vector<double> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];

  sort(v.begin(), v.end(), greater<double>());
  int sum = 0;
  for (int i = 0; i < A; i++) sum += v[i];
}