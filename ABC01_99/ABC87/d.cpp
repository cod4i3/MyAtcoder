#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MAX_N 100100
#define all(x) (x).begin(), (x).end()
bool seen[MAX_N];

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<ll, ll> > man;
  vector<ll> D;
  vector<ll> plot(MAX_N, 0);
  for (int i = 0; i < M; i++) {
    ll l, r, d;
    cin >> l >> r >> d;
    if (l > r) {
      ll tmp = r;
      r = l;
      l = tmp;
      d = -d;
    }
    man.push_back(make_pair(l, r));
    D.push_back(d);
  }

  for (int i = 0; i < M; i++) {
    ll left = man[i].first;
    ll right = man[i].second;
    if (seen[right]) {
      if (plot[right] != plot[left] + D[i]) {
        cout << "No" << endl;
        return 0;
      } else
        continue;
    } else
      plot[right] = plot[left] + D[i];
    seen[right] = true;
  }

  cout << "Yes" << endl;
  return 0;
}