#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  int box[60];
  for (int i = 0; i < N; i++) {
    box[i] = 0;
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int w;
    cin >> w;
    for (int j = 0; j < N; j++) {
      if (box[j] == 0) {
        box[j] = w;
        ans++;
        break;
      }

      if (box[j] < w)
        continue;
      else {
        box[j] = w;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}