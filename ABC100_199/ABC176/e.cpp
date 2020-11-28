#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int H, W, M;
  cin >> H >> W >> M;

  vector<int> bomH(H, 0);
  vector<int> bomW(W, 0);
  vector<int> hig(H, 0);
  vector<int> wid(W, 0);
  for (int i = 0; i < M; i++) {
    int h, w;
    cin >> h >> w;
    h--, w--;
    bomH[h]++, bomW[w]++;
    hig[h]++, wid[w]++;
  }

  sort(bomH.rbegin(), bomH.rend());
  sort(bomW.rbegin(), bomW.rend());
  sort(hig.begin(), hig.end());
  sort(wid.begin(), wid.end());

  
}