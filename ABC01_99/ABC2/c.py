x1, y1, x2, y2, x3, y3 = map(int, input().split())
v1 = [x1 - x2, y1 - y2]
v2 = [x1 - x3, y1 - y3]
S = abs(v1[0] * v2[1] - v1[1] * v2[0])
print(S / 2)