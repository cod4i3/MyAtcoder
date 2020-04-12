from math import sqrt


def length(x1, x2, y1, y2):
    return sqrt((x2 - x1)**2 + (y2 - y1)**2)


x1, y1, r = map(int, input().split())
x2, y2, x3, y3 = map(int, input().split())
if(x2 <= x1 - r and x1 + r <= x3 and y2 <= y1 - r and y1 + r <= y3): print('NO')
else: print('YES')
X, Y = (x2 + x3) / 2, (y2 + y3) / 2
if (length(x1, x2, y1, y2) <= r and length(x1, x3, y1, y3) <= r and
    length(x1, x3, y1, y2) <= r and length(x1, x2, y1, y3) <= r and
    length(x1, X, y1, Y) <= r): print('NO')
else: print('YES')
