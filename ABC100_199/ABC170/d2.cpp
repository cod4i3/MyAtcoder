#pragma GCC optimize("Ofast")
#include <math.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

bool IsPrime(int num) {
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;  // 偶数はあらかじめ除く

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2) {
    if (num % i == 0) {
      // 素数ではない
      return false;
    }
  }

  // 素数である
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A;
  map<int, int> db;
  vector<int> seen(N, 0);
  int a;

  // Aを単一リストに
  for (int i = 0; i < N; i++) {
    cin >> a;
    if (db[a]) {
      db[a]++;
      continue;
    }
    db[a]++;
    A.emplace_back(a);
  }
  sort(A.begin(), A.end(), std::greater());

  int ans = 0;
  // 割り切れる物は1とする
  for (int i = 0; i < A.size(); i++) {
    if (db[A[i]] >= 2) {
      continue;
    } else if (IsPrime(A[i])) {
      ans++;
      continue;
    } else {
      bool flag = true;
      for (int j = i + 1; j < A.size(); j++) {
        if (A[i] % A[j] == 0) {
          flag = false;
          break;
        }
      }
      if (flag) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
