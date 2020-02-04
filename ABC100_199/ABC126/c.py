N, K = map(int, input().split())
ans = 0.0
for i in range(1, N + 1):
    cnt, cur = 0, i
    while (cur < K):
        cur *= 2
        cnt += 1
    ans += 1 / N * (0.5 ** cnt)
print(ans)
