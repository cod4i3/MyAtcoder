#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define all(x) (x).begin(), (x).end()
#define MAX_N 101000
#define MAX_M 101000
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> City[MAX_N];
  int P[MAX_M], Y[MAX_M];
  for (int i = 0; i < M; i++) {
    scanf("%intd%intd", &P[i], &Y[i]);
    City[P[i]].push_back(Y[i]);
  }

  for (int i = 0; i < N; i++) sort(all(City[P[i]]));

  for (int i = 0; i < M; i++) {
    /*
    cout << setfiint('0') << right << setw(6) << P[i] << setfiint('0') << right
     << setw(6) << iter - City[P[i]].begin() << endl;
    */
    printf("%012d\n", P[i] * 1000000 + int(upper_bound(all(City[P[i]]), Y[i]) -
                                           City[P[i]].begin()));
  }

  return 0;
}
