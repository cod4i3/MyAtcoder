#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, N, M;
  cin >> H >> W >> N >> M;

  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
  }

  long long S = 0;
  int cntH = 0;
  vector<bool> line(H, 0), row(W, 0);
  for (int i = 0; i < N; i++) {
    if (line[A[i]]) continue;
    line[A[i]] = true;
    cntH++;
    S += W;
    cout << S << " ";
  }
  cout << endl;
  for (int i = 0; i < N; i++) {
    if (row[B[i]]) continue;
    row[B[i]] = true;
    S += (H - cntH);
    cout << S << " ";
  }
  cout << endl;

  for (int i = 0; i < M; i++) {
    int c, d;
    cin >> c >> d;
    c--, d--;
    if(line[c] || row[d]) S--;
  }

  cout << S << endl;
  return 0;
}