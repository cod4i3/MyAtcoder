N = int(input())
P = list(map(int, input().split()))
M = 10000000
ans = 0
for i in range(N):
  if (P[i] <= M):
    ans += 1
    M = P[i]
print(ans)