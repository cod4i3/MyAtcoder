from decimal import *
n, m = map(Decimal, input().split())
n %= 12
ans = abs((5 * n + m / 12) - m) * 6
print(360 - ans) if(ans > 180) else print(ans)
