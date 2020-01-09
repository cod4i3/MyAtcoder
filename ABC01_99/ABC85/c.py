N, Y = map(int, input().split())
flag = False
for x in range(N + 1):
    for y in range(0, N - x + 1):
        if 10000 * x + 5000 * y + 1000 * (N - x - y) == Y:
            print(x, y, N - x - y)
            flag = True
            exit()
if (not flag): print("-1 -1 -1")
