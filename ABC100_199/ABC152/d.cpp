#include <iostream>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_N 2000000

int main() {
  int N;
  cin >> N;
  int same[MAX_N];
  REP(i, N) {
    if (i < 1000000 && i % 111111 == 0)
      same[i] = 11112;
    else if (i < 100000 && i % 11111 == 0)
      same[i] = 1112;
    else if (i % 1111 == 0)
      same[i] = 112;
    else if (i % 111 == 0)
      same[i] = 12;
  }
  if (i % 111111 == 0):
}