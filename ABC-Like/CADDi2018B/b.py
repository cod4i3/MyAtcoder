N, H, W = map(int, input().split())
ans = 0
for i in range(N):
  A, B = map(int, input().split())
  ans += min(A//H, B//W)
print(ans)