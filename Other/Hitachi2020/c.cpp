#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using namespace std;

int main() {
  int N;
  cin >> N;
  Graph G(N);
  REP(i, N) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}