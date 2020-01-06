#include <iostream>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  string image[H + 1];

  for (int i = 1; i <= H; i++) {
    cin >> image[i];
  }

  for (int i = 1; i <= 2 * H; i++) {
    cout << image[(i + 1) / 2] << endl;
  }

  return 0;
}