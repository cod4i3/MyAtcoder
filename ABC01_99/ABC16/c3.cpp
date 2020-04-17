#include <cstring>
#include <iostream>
using namespace std;
#define MAX_V 15
#define INF 735477
// d[u][v]は辺 e = (u, v)のコスト（存在しない場合はINF,ただしd[i][i] = 0)
// Vは頂点数
int d[MAX_V][MAX_V];
int V;

void warshall_floyd() {
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  V = N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j)
        d[i][j] = 0;
      else
        d[i][j] = INF;
    }
  }

  for (int i = 0; i < M; i++) {
    int n, m;
    cin >> n >> m;
    n--;
    m--;
    d[n][m] = d[m][n] = 1;
  }
  
  warshall_floyd();

  for (int i = 0; i < N; i++) {
    int ans = 0;
    for (int j = 0; j < N; j++) {
      if (d[i][j] == 2) ans++;
    }
    cout << ans << endl;
  }

  return 0;
}