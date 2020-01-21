N, T = map(int, input().split())
c, t = [0] * N, [0] * N
ans = 100000
for i in range(N):
    c[i], t[i] = map(int, input().split())
    if t[i] <= T: ans = min(ans, c[i])
print(ans) if ans <= 1000 else print('TLE')
