#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  vector<vector<int>> S(H, vector<int>(W));

  int sum = W * B;
  if (sum % H) {
    cout << "No" << endl;
    return 0;
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
    }
  }
}