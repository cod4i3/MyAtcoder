#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct plot {
  int_least16_t X;
  int Y;
  ll H;
};

void printAns(int x, int y, ll z) { cout << x << ' ' << y << ' ' << z << endl; }

bool plotCompareH(const plot& p1, const plot& p2) { return p1.H > p2.H; }

int main() {
  int N;
  cin >> N;
  vector<plot> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i].X >> p[i].Y >> p[i].H;
  }

  sort(p.begin(), p.end(), plotCompareH);

  if (N == 1) {
    printAns(p[0].X, p[0].Y, p[0].H);
    return 0;
  }

  for (int Cx = 0; Cx <= 100; Cx++) {
    for (int Cy = 0; Cy <= 100; Cy++) {
      ll Top = abs(Cx - p[0].X) + abs(Cy - p[0].Y) + p[0].H;
      int cnt = 1;
      for (int i = 1; i < N; i++) {
        if (p[i].H == max(Top - abs(p[i].X - Cx) - abs(p[i].Y - Cy), 0LL))
          cnt++;
      }
      if (cnt == N) {
        printAns(Cx, Cy, Top);
        return 0;
      }
    }
  }
  return 0;
}
