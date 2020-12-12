#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<int>> C(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> C[i][j];
    }
  }

  vector<vector<int>> even(H, vector<int>(W, 0)), odd(H, vector<int>(W, 0));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int c = C[i][j];
      if ((i + j) % 2) {
        if (i == 1 && j == 0)
          odd[i][j] = c;
        else if (i == 0 && j == 1)
          odd[i][j] = c;
        else if (i == 0)
          odd[i][j] = odd[i][j - 1] + c;
        else
          odd[i][j] = odd[i - 1][j] + c;
        if (i + 1 < H) odd[i + 1][j] = odd[i][j];
        if (j + 1 < W) odd[i][j + 1] = odd[i][j];
      } else {
        if (i == 0 && j == 0)
          even[i][j] = c;
        else if (i == 0)
          even[i][j] = even[i][j - 1] + c;
        else 
          even[i][j] = even[i - 1][j] + c;
        if (i + 1 < H) even[i + 1][j] = even[i][j];
        if (j + 1 < W) even[i][j + 1] = even[i][j];
      }
    }
  }

  for(int i=0; i<H; i++){
      for(int j=0; j<W; j++)cout <<even[i][j] << " ";
      cout << endl;
  }

  for(int i=0; i<H; i++){
      for(int j=0; j<W; j++)cout <<odd[i][j] << " ";
      cout << endl;
  }


  cout << ans << endl;
  return  0;
}