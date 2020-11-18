N = int(input())
A = list(map(int, input().split()))
ans, res = 0, 0
seen = [0] * 1001
for i in range(2, 1001):
  if(seen[i]): continue
  for j in range(i*2, 1001, i):
    seen[j] = 1
  cnt = 0
  for j in range(N):
    if(A[j] % i == 0): cnt += 1
  if(cnt >= res):
    res = cnt
    ans = i

print(ans)