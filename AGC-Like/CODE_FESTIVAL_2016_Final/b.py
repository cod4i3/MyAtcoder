N = int(input())
res, cnt = 0, 0
seen = [1] * (5 * 10**3)
for i in range(1, N + 1):
    res += i
    if(res >= N):
        cnt = i
        break
for i in range(cnt, -1, -1):
    if(res == N):
        break
    if(res - i >= N):
        res -= i
        seen[i] -= 1
for i in range(1, cnt + 1):
    if(seen[i]): print(i)
