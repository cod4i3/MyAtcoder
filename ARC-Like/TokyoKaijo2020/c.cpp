#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N, 0);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  // imos法用のやつ、答え
  vector<int> B(3 * (N + 1), 0);
  vector<int> table(3 * (N + 1), 0);
  vector<int> ans(N, 1);
  for (int i = 0; i < N; i++) {
    if (A.at(i)) {
      B.at(N + i - A.at(i))++;
      B.at(N + i + A.at(i) + 1)--;
    }
  }

  int sum = 0;
  for (int i = 0; i < 3 * (N + 1); i++) {
    sum += B.at(i);
    table.at(i) += sum;
  }

  for (int i = 0; i < 3 * (N + 1); i++) {
    cout << B.at(i) << " ";
  }
  cout << endl;
  for (int i = 0; i < 3 * (N + 1); i++) {
    cout << table.at(i) << " ";
  }

  for (int i = 0; i < N; i++) {
    ans.at(i) += table.at(i + N - 1);
  }
  cout << endl;
  for (int i = 0; i < N; i++) {
    if (A.at(i)) ans.at(i)--;
    cout << ans.at(i) << " ";
  }
  cout << endl;
  return 0;
}