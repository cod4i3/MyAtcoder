m, n, N = map(int, input().split())
r, sell, ans = 0, N, 0
while (sell != 0):
    ans += sell
    sell = (N // m) * n
    r = N % m
    N = sell + r
print(ans)
