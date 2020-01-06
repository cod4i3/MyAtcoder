#include <iostream>
#include <vector>
using namespace std;
#define MAX 1

std::vector<bool> IsPrime;

void sieve(size_t num) {
  if (num + 1 > IsPrime.size()) {  // resizeで要素数が減らないように
    IsPrime.resize(num + 1, true);  // IsPrimeに必要な要素数を確保
  }
  IsPrime[0] = false;  // 0は素数ではない
  IsPrime[1] = false;  // 1は素数ではない

  for (size_t i = 2; i * i <= num; ++i)      // 0からsqrt(max)まで調べる
    if (IsPrime[i])                          // iが素数ならば
      for (size_t j = 2; i * j <= num; ++j)  // (max以下の)iの倍数は
        IsPrime[i * j] = false;              // 素数ではない
}

int main() {
  int x;
  cin >> x;
  sieve(110000);
  for (int i = x; i < 110000; i++) {
    if (IsPrime[i]) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}