#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

/*
   x1,x2,y1,y2とやったらy1がnamespaceに入ってたらしく不適
   よってax, ay…でおこなった
    y - ay =( (by - ay)/(bx - ax) ) * (x - ax)
    (y - ay)(bx - ax) = (by - ay)(x - ax)
    (ax - bx)(y - ay) + (by - ay)(x - ax) = 0
    (ax - bx)(y - ay) + (ay - by)(ax - x) = 0
    後はここに(cx, cy), (dx, dy)を代入
    対称性より
    (cx - dx)(y - cy) + (cy - dy)(cx - x) = 0
*/

int ax, ay, bx, by;
bool crossing(int cx, int cy, int dx, int dy) {
  ll ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
  ll tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
  ll tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
  ll td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);
  return ta * tb < 0 && tc * td < 0;
}

int main() {
  int N;
  cin >> ax >> ay >> bx >> by;
  cin >> N;

  vector<vector<int>> p(N, vector<int>(2));
  for (int i = 0; i < N; i++) cin >> p[i][0] >> p[i][1];
  p.emplace_back(vector<int>{p[0][0], p[0][1]});

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int cx = p[i][0], cy = p[i][1];
    int dx = p[i + 1][0], dy = p[i + 1][1];
    ans += crossing(cx, cy, dx, dy);
  }

  cout << ans / 2 + 1 << endl;
  return 0;
}