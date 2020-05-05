x, y = map(int, input().split())
ans = 0
if (x == 0):
    print(y) if (y >= 0) else print(-y + 1)
elif (y == 0):
    print(x + 1) if(x > 0) else print(-x)
elif (x > 0 and y > 0):
    if (y >= x): print(abs(y - x))
    elif (x > y): print(abs(y - x) + 2)
elif (x < 0 and y < 0):
    if (y <= x): print(abs(y - x) + 2)
    elif (x < y): print(abs(y - x))
elif (x > 0 and y < 0):
    print(abs(-y - x) + 1)
elif (x < 0 and y > 0):
    print(1 + abs(y + x))
