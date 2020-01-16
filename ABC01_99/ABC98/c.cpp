#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  // 'E'の累積和
  int E[N];
  int L = 0, R = 0, ans = 0;
  S[0] == 'E' ? E[0] = 1 : E[0] = 0;
  for (int i = 1; i < N; i++) {
    if (S[i] == 'E')
      E[i] = E[i - 1] + 1;
    else
      E[i] = E[i - 1];
  }
  // 0番目がリーダー、この時最小値の時もあるのでE[N-1]とする
  // 仮にこのansをE[N-1]-1とおくと、WWWWWEEEとかの時に困る。
  // ans = Nじゃない時はs.at(0)='E'だが、その場合1番目リーダーの時に
  // どうせNより小さくなるから問題ない
  
  ans = E[N - 1];
  // i番目がリーダー
  for (int i = 1; i < N; i++) {
    L = i - E[i - 1];
    R = E[N - 1] - E[i];
    int cur = L + R;
    ans = min(cur, ans);
  }
  cout << ans << endl;
}
