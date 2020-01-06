#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 60
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > G(MAX_N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for (int i = 1; i <= N; i++) cout << G[i].size() << endl;

  return 0;
}