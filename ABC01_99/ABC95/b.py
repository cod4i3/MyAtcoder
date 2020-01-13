n, x = map(int, input().split())
m = [int(input()) for i in range(n)]
ans, x = n, x - sum(m)
while (x - min(m) >= 0):
    x, ans = x - min(m), ans + 1
print(ans)
