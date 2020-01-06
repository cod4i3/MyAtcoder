#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  long double a, b, x;
  cin >> a >> b >> x;
  if (x >= a * a * b / 2) {
    long double alpha = (2 * (a * a * b - x)) / (a * a * a);
    long double ans = atan(alpha) * 180 / M_PI;

    printf("%.10Lf\n", ans);
    return 0;
  } else {
    long double alpha = (a * b * b) / (2 * x);
    long double ans = atan(alpha) * 180 / M_PI;

    printf("%.10Lf\n", ans);
    return 0;
  }
}