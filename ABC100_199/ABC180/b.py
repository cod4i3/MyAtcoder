from decimal import *
N = int(input())
x = list(map(Decimal, input().split()))
m, y, c = Decimal(0), Decimal(0), Decimal(0)
for i in range(N):
    m += abs(x[i])
    y += x[i]**2
    c = max(c, abs(x[i]))
y = y.sqrt()
print(m)
print(y)
print(c)
