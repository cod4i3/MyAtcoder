N, T = map(int, input().split())
t = [int(i) for i in input().split()]
ans = T
for i in range(0, N - 1):
    ans += min(t[i + 1] - t[i], T)
print(ans)
