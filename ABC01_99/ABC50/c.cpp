#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define ll long long

int main() {
  int N;
  cin >> N;
  vector<long long> v(N, 0);
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    v[a]++;
  }

  long long ans = 1;

  //偶数なら初期値1、奇数なら初期値0
  for (int i = (N % 2 == 0) ? 1 : 0; i < N; i += 2) {
    //奇数で0が一つじゃ無い時と、数値が2以外の時
    if ((i == 0 && v[0] != 1) || (i != 0 && v[i] != 2)) {
      ans = 0;
      break;
    } else
      ans = ans * v[i] % 1000000007;
  }

  cout << ans << endl;

  return 0;
}
