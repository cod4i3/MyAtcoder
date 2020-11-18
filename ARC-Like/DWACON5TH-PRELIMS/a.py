N = int(input())
a = list(map(int, input().split()))

ans, res, ave = 0, max(a), sum(a)/N
for i in range(N):
  if(abs(ave - a[i]) < res):
    ans = i
    res = abs(ave - a[i])
print(ans)