#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> a;
  for (int i = 0; i < n; i++) {
    ll num;
    cin >> num;
    a.push_back(num);
  }

  ll sumPlus = 0, sumMinus = 0;
  ll ansPlus = 0, ansMinus = 0;

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (sumPlus + a[i] <= 0) {
        ansPlus += abs(sumPlus + a[i]) + 1;
        sumPlus = 1;
      } else
        sumPlus += a[i];
      if (sumMinus + a[i] >= 0) {
        ansMinus += abs(sumMinus + a[i]) + 1;
        sumMinus = -1;
      } else
        sumMinus += a[i];
    } else {
      if (sumPlus + a[i] >= 0) {
        ansPlus += abs(sumPlus + a[i]) + 1;
        sumPlus = -1;
      } else
        sumPlus += a[i];
      if (sumMinus + a[i] <= 0) {
        ansMinus += abs(sumMinus + a[i]) + 1;
        sumMinus = 1;
      } else
        sumMinus += a[i];
    }
  }

  cout << min(ansPlus, ansMinus) << endl;
  return 0;
}