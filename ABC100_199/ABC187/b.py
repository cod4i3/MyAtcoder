N = int(input())
x, y = [0] * N, [0] * N
for i in range(N): x[i], y[i] = map(int, input().split())

ans = 0
for i in range(N - 1):
    for j in range(i + 1, N):
      Y, X = y[j] - y[i], x[j] - x[i]
      if(-1 <= Y/X <= 1): ans += 1
print(ans)