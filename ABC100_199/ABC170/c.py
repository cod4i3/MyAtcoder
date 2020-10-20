X, N = map(int, input().split())
P = list(map(int, input().split()))
if(N == 0):
    print(X)
    exit(0)

L = []
for i in range(1, 101):
    if(i in P): continue
    else: L.append(i)
m = 1000
for l in L:
    m = min(m, abs(X - l))
ans = []
for l in L:
    if(abs(X - l) == m):
        ans.append(l)
ans.sort()
print(ans[0])
