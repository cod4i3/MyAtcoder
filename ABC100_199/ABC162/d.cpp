#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  // それぞれR,G,Bの文字の位置
  vector<int> R, G, B;

  FOR(i, N) {
    //  i+1 じゃなくて i なのは
    //  j - i = k - j において各変数に1を加えても結果は同じである為

    if (S[i] == 'R') R.emplace_back(i);
    if (S[i] == 'G') G.emplace_back(i);
    if (S[i] == 'B') B.emplace_back(i);
  }

  int r = R.size();
  int g = G.size();
  int b = B.size();
  ll ans = r * g * b;
  ll m = 0;

  // i,jがループの変数にも使われててややこしいのはごめんなさい
  // 下の説明の i,j,k は適宜 R[i],G[j] とかに置き換えてください
  FOR(i, r) {
    FOR(j, g) {
      // j - i ≠ k - j より k ≠ 2j - i なので
      // k = 2j -i となる組み合わせが存在したら取り除いています、以下2ループも同様
      if (binary_search(all(B), 2 * G[j] - R[i]) && G[j] > R[i]) m--;
      if (binary_search(all(B), 2 * R[i] - G[j]) && R[i] > G[j]) m--;
    }
  }

  FOR(i, g) {
    FOR(j, b) {
      if (binary_search(all(R), 2 * B[j] - G[i]) && B[j] > G[i]) m--;
      if (binary_search(all(R), 2 * G[i] - B[j]) && G[i] > B[j]) m--;
    }
  }

  FOR(i, b) {
    FOR(j, r) {
      if (binary_search(all(G), 2 * R[j] - B[i]) && R[j] > B[i]) m--;
      if (binary_search(all(G), 2 * B[i] - R[j]) && B[i] > R[j]) m--;
    }
  }

  // testcase17,18の2つが通りませんでした
  cout << ans + m << endl;
  return 0;
}



