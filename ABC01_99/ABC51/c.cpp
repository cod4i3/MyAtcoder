#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void moveR(int x1, int x2) {
  for (int i = 0; i < x2 - x1; i++) {
    cout << 'R';
  }
}

void moveU(int y1, int y2) {
  for (int i = 0; i < y2 - y1; i++) {
    cout << 'U';
  }
}

void moveL(int x1, int x2) {
  for (int i = 0; i < x2 - x1; i++) {
    cout << 'L';
  }
}

void moveD(int y1, int y2) {
  for (int i = 0; i < y2 - y1; i++) {
    cout << 'D';
  }
}

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  moveR(sx, tx);
  moveU(sy, ty);
  moveL(sx, tx);
  moveD(sy, ty);
  cout << 'D';
  moveR(sx, tx + 1);
  moveU(sy, ty + 1);
  cout << 'L' << 'U';
  moveL(sx, tx + 1);
  moveD(sy, ty + 1);
  cout << 'R' << endl;
  return 0;
}