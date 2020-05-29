N, x = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
ans, cur = 0, 0
if(sum(a) <= x):
    if(sum(a) != x): N -= 1
    print(N)
    exit(0)

for i in range(N):
    cur += a[i]
    if(cur > x): break
    ans += 1
print(ans)
