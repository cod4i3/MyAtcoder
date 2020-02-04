#include <iostream>
#include <vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N), C(N-1);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < N - 1; i++) cin >> C[i];

  vector<pair<int, int>> D;
  for (int i = 0; i < N; i++) {
      D.emplace_back(make_pair(A[i], B[A[i]]));
  }

  int ans = accumulate(A.begin(), A.end(), 0);
  for(int i=1;i<N;i++){
  }
  cout << ans << endl;
  return 0;
}