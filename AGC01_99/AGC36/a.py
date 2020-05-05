S = int(input())
x1, y1 = 0, 0
x2, y2 = 10 ** 9, 1
y3 = S // (10 ** 9) + 1
x3 = 10 ** 9 * y3 - S
if (S == 10 ** 18):
    print(0, 0, 10**9, 0, 0, 10**9)
else:
    print(x1, y1, x2, y2, x3, y3)
