#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int ans;
int N, M;

vector<int> dist;
void bfs(int s, const vector<vector<int>> &r, int cnt) {
  queue<int> que;
  dist[s] = 0;
  que.push(s);

  while (!que.empty()) {
    int t = que.front();
    que.pop();

    for (auto f : r[t]) {
      if (dist[f] >= 0) continue;
      dist[f] = dist[t] + 1;
      que.push(f);
    }
  }

  for (int i = 0; i < N; i++) {
    if (dist[i] == 2) ans++;
  }
}

int main() {
  cin >> N >> M;
  vector<vector<int>> relate(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    relate[a].emplace_back(b);
    relate[b].emplace_back(a);
  }

  for (int i = 0; i < N; i++) {
    dist.assign(N, -1);
    ans = 0;
    bfs(i, relate, 0);

    cout << ans << endl;
  }

  return 0;
}