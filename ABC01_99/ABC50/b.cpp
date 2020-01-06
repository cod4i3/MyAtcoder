#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int T[N + 1];
  for (int i = 1; i <= N; i++) {
    cin >> T[i];
  }

  int M;
  cin >> M;
  int sum[M + 1];

  for (int i = 1; i <= M; i++) {
    int a, b;
    cin >> a >> b;
    sum[i] = 0;
    for (int j = 1; j <= N; j++) {
      if (j == a) {
        sum[i] += b;
      } else {
        sum[i] += T[j];
      }
    }
  }

  for (int i = 1; i <= M; i++) cout << sum[i] << endl;
  return 0;
}