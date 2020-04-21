#include <iostream>
#include <vector>
using namespace std;
bool not_prime[127160];
bool not_prime_judge(int N) {
  if (N == 1) return true;
  for (int i = 2; i * i <= N; i++) {
    if (N % i == 0) return true;
  }
  return false;
}

int main() {
  int Q;
  cin >> Q;
  vector<pair<int, int>> num(Q);
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    num[i] = make_pair(l, r);
  }
  for (int i = 3; i < 127160; i++) {
    if (not_prime[i]) continue;
    if (not_prime_judge(i)) {
      for (int j = i; j < 127160; j += i) not_prime[j] = true;
      not_prime[i] = true;
    } else if (not_prime_judge((i + 1) / 2)) {
      not_prime[i] = true;
    } else
      not_prime[i] = false;
  }

  not_prime[0] = not_prime[1] = not_prime[2] = true;

  vector<int> sum(127160, 0);
  sum[0] = 0;
  for (int i = 0; i < 127160; i++) {
    if (not_prime[i])
      sum[i] = sum[i - 1];
    else
      sum[i] = sum[i - 1] + 1;
  }


  for (int i = 0; i < Q; i++) {
    int l = num[i].first, r = num[i].second;
    if (l == 0)
      cout << sum[r] << endl;
    else
      cout << sum[r] - sum[l - 1] << endl;
  }

  return 0;
}
