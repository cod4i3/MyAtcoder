#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
// ほぼACLと同じ
int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n)) x++;
  return x;
}

template <class S, S (*op)(S, S), S (*e)()>
struct SegTree {
 public:
  SegTree() : SegTree(0) {}
  SegTree(int n) : SegTree(std::vector<S>(n, e())) {}
  SegTree(const std::vector<S>& v) : _n(int(v.size())) {
    log = ceil_pow2(_n);
    size = 1 << log;
    data = std::vector<S>(2 * size, e());
    for (int i = 0; i < _n; i++) data[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    data[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }

  S get(int p) {
    assert(0 <= p && p < _n);
    return data[p + size];
  }

  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    S sml = e(), smr = e();
    l += size;
    r += size;

    while (l < r) {
      if (l & 1) sml = op(sml, data[l++]);
      if (r & 1) smr = op(data[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }

  S all_prod() { return data[1]; }

  template <bool (*f)(S)>
  int max_right(int l) {
    return max_right(l, [](S x) { return f(x); });
  }
  template <class F>
  int max_right(int l, F f) {
    assert(0 <= l && l <= _n);
    assert(f(e()));
    if (l == _n) return _n;
    l += size;
    S sm = e();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!f(op(sm, data[l]))) {
        while (l < size) {
          l = (2 * l);
          if (f(op(sm, data[l]))) {
            sm = op(sm, data[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, data[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }

  template <bool (*f)(S)>
  int min_left(int r) {
    return min_left(r, [](S x) { return f(x); });
  }
  template <class F>
  int min_left(int r, F f) {
    assert(0 <= r && r <= _n);
    assert(f(e()));
    if (r == 0) return 0;
    r += size;
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!f(op(data[r], sm))) {
        while (r < size) {
          r = (2 * r + 1);
          if (f(op(data[r], sm))) {
            sm = op(data[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = op(data[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

 private:
  int _n, size, log;
  std::vector<S> data;

  void update(int k) { data[k] = op(data[2 * k], data[2 * k + 1]); }
};

ll op(ll a, ll b) { return a ^ b; }
ll e() { return 0; }
int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  vector<ll> ans;
  SegTree<ll, op, e> tree(A);
  for (int i = 0; i < Q; i++) {
    int T;
    ll X, Y;
    cin >> T >> X >> Y;
    X--;
    if (T == 1) {
      ll res = tree.get(X);
      res ^= Y;
      tree.set(X, res);
    } else {
      ans.emplace_back(tree.prod(X, Y));
    }
  }

  for (int i = 0; i < int(ans.size()); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}