#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int> >;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> city;
  REP(i, R) {
    int r;
    cin >> r;
    R.push_back(r);
  }
}