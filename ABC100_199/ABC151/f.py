import math
N = int(input())
x = [0] * N
y = [0] * N
for i in range(N):
    x[i], y[i] = map(int, input().split())
dx = max(x) - min(x)
dy = max(y) - min(y)
dx /= 2
dy /= 2
print(math.sqrt(dx**2 + dy**2))
