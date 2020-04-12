N, a, b, L = map(int, input().split())
ans = 0
for i in range(N):
  t = L / a
  L = t * b
print(L)
