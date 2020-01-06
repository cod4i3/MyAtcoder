#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int W, H, N;
  cin >> W >> H >> N;
  int x[N], y[N], a[N];
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> a[i];
  }

  int l = 0, r = W, u = H, d = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] == 1) {
      if (l <= x[i]) {
        l = x[i];
      }
    }

    if (a[i] == 2) {
      if (r >= x[i]) {
        r = x[i];
      }
    }

    if (a[i] == 3) {
      if (d <= y[i]) {
        d = y[i];
      }
    }

    if (a[i] == 4) {
      if (u >= y[i]) {
        u = y[i];
      }
    }
  }

  int width = (r - l);
  int height = (u - d);

  if (width <= 0) width = 0;
  if (height <= 0) height = 0;
  cout << width * height << endl;
  return 0;
}