N = int(input())
ans = 0
for i in range(N):
    x, u = input().split()
    if u == 'JPY': ans += float(x)
    else: ans += 380000.0 * float(x)
print(ans)
