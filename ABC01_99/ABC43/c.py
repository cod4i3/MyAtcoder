N = int(input())
a = list(map(int,input().split()))
a.sort()
ans = 10**9
for y in range(a[0], a[-1]+1):
  sum = 0
  for i in range(N):
    x = a[i]
    sum += (x-y)**2
  ans = min(ans, sum)
  if(ans == 0): break
print(ans)