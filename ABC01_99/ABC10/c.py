from math import sqrt
xa, ya, xb, yb, T, V = map(int, input().split())
n = int(input())
x, y = [0] * n, [0] * n
for i in range(n):
    x[i], y[i] = map(int, input().split())
for i in range(n):
    d = 0
    d += sqrt((x[i] - xa) ** 2 + (y[i] - ya) ** 2)
    d += sqrt((x[i] - xb) ** 2 + (y[i] - yb) ** 2)
    if (d <= T * V):
        print('YES')
        exit(0)
print('NO')
