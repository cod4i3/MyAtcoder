#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define ll long long
#define INFTY 1 << 21

int main() {
  int N;
  cin >> N;

  double x[N], y[N];
  double max_length = 0;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }

  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      max_length =
          max(max_length, sqrt(pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2)));
    }
  }

  cout << max_length << endl;
}
