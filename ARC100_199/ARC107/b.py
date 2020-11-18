N, K = map(int, input().split())
res, ans = 0, 0
for i in range(1, N+1):
  a = i
  if(K >= i):
    res = 2*N - (K - i) - 1
    ans += res
  else:
    