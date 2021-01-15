#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  // 後ろからi日目でi日後の仕事が使える
  vector<vector<int>> work(M, vector<int>());
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    if (a >= M) continue;
    work[a].emplace_back(b);
  }

  priority_queue<int> que;
  for (int i = 0; i < M; i++) {
    int l = work[i].size();
    if (l != 0) sort(work[i].begin(), work[i].end(), greater<int>());
  }

  long long ans = 0;
  for (int i = 0; i < M; i++) {
    int l = work[i].size();
    for (int j = 0; j < l; j++) que.push(work[i][j]);
    if (!que.empty()) {
      ans += que.top();
      que.pop();
    }
  }

  cout << ans << endl;
  return 0;
}