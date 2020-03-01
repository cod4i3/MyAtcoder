#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  for (int i = 0; i < N; i++) cin >> d[i];
  sort(all(d));

  if (N == 1) {
    cout << d[0] << endl << d[0] << endl;
    return 0;
  }

  int MAX = *max_element(all(d));
  int sum = accumulate(all(d), 0);
  cout << sum << endl;

  if(MAX <= sum - MAX){
    cout << 0 << endl;
    return 0;
  }else{
    cout << MAX - (sum - MAX) << endl;
    return 0;
  }
}