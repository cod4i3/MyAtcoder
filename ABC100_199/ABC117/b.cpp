#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// STLの練習
int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++) cin >> L[i];
  int sum = accumulate(L.begin(), L.end(), 0);
  int Lmax = *max_element(L.begin(), L.end());
  if (sum - Lmax > Lmax)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}