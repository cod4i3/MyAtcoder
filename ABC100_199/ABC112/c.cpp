#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct plot {
  int x;
  int y;
  ll z;
};

void printAns(int x, int y, ll z) { cout << x << ' ' << y << ' ' << z << endl; }

int main() {
  int N;
  cin >> N;
  vector<plot> p(N);
  vector<plot> v(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i].x >> p[i].y >> p[i].z;
  }

  for (int i = 0; i < N; i++) {
    v[i].x = p[i].x - p[0].x;
    v[i].y = p[i].y - p[0].y;
    v[i].z = p[i].z - p[0].z;
    if (p[i].x == 0 && p[i].y == 0 && v[i].z > 0) {
      printAns(p[i].x, p[i].y, p[i].z);
      return 0;
    }

    if (p[0].x == 0 && p[0].y == 0 && v[i].z < 0) {
      printAns(p[0].x, p[0].y, p[0].z);
      return 0;
    }
  }

  if (v[1].z * v[2].z > 0) {
    printAns(p[0].x + v[1].x + v[2].x, p[0].y + v[1].y + v[2].y,
             p[0].z + v[1].z + v[2].z);
    return 0;
  }

  else if (v[0].z == 0 && v[1].z == 0) {
    printAns((p[0].x + p[3].x) / 2, (p[0].y + p[3].y) / 2,
             (p[0].z + p[3].z) / 2 +
                 abs(abs(p[3].x - p[0].x) + abs(p[3].y - p[0].y)) / 2);
    return 0;
  } else {
    printAns((p[0].x + v[1].x + v[2].x), (p[0].y + v[1].x + v[2].x),
             p[0].z + v[1].z + v[2].z);
    return 0;
  }

  return 0;
}
