#include <iostream>
using namespace std;
using ll = long long;

int N, A, B, C;
void p_m(int *A, int *B) {
  A += 1;
  B -= 1;
  return;
}

int main() {
  cin >> N >> A >> B >> C;
  string S;
  for (int i = 0; i < N; i++) {
    cin >> S;
    if (S == "AB") {
      if (A >= B)
        p_m(&A, &B);
      else
        p_m(&B, &A);
    }

    if (S == "AB") {
      if (A >= B)
        p_m(&A, &B);
      else
        p_m(&B, &A);
    }

    if (S == "AB") {
      if (A >= B)
        p_m(&A, &B);
      else
        p_m(&B, &A);
    }

    if (A < 0 || B < 0 || C < 0) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}