#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0 #include<iostream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)

void bfs(vector<int> &ans, vector<vector<int>> &Graph) {
  queue<int> que;
  que.push(0);
  ans[0] = 0;

  while (!que.empty()) {
    int cur = que.front();
    que.pop();
    for (int next : Graph[cur]) {
      if (ans[next] != -1) continue;
      que.push(next);
      ans[next] = cur;
    }
  }
  return;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> Graph(N);
  vector<int> ans(N, -1);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b, a--, b--;
    Graph[a].emplace_back(b);
    Graph[b].emplace_back(a);
  }

  bfs(ans, Graph);

  cout << "Yes" << endl;
  for (int i = 1; i < N; i++) {
    cout << ans[i] + 1 << endl;
  }
  return 0;
}