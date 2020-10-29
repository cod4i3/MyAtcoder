from decimal import *
from math import sqrt
s = list(map(Decimal, input().split()))
N = int(input())
p = [list(map(Decimal, input().split())) for _ in range(N)]

ans = Decimal(1000)
for i in range(N - 1):
    x0, y0 = s[0], s[1]
    x1, y1, x2, y2 = p[i][0], p[i][1], p[i + 1][0], p[i + 1][1]
    a, b, c = y2 - y1, -(x2 - x1), y2 * (x2 - x1) - x2 * (y2 - y1)
    d1 = Decimal(abs(a * x0 + b * y0 + c))
    d2 = Decimal(sqrt(a**2 + b**2))
    if(Decimal(d1 / d2) < ans): ans = Decimal(d1 / d2)

x0, y0 = s[0], s[1]
x1, y1, x2, y2 = p[N - 1][0], p[N - 1][1], p[0][0], p[0][1]
a, b, c = y2 - y1, -(x2 - x1), y2 * (x2 - x1) - x2 * (y2 - y1)
d1 = Decimal(abs(a * x0 + b * y0 + c))
d2 = Decimal(sqrt(a**2 + b**2))
if(Decimal(d1 / d2) < ans): ans = Decimal(d1 / d2)

print(ans)
