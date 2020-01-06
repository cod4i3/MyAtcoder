a, b, c, d = map(int, input().split())
if (d < a or b < c): print(0)
else: print(min(b, d) - max(a, c))
