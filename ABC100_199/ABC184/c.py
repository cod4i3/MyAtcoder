dx = [0, 1, 0, -1, 1, 1, -1, -1]
dy = [1, 0, -1, 0, 1, -1, 1, -1]

r1, c1 = map(int, input().split())
r2, c2 = map(int, input().split())
r1, c1 = abs(r1), abs(c1)
r2, c2 = abs(r2), abs(c2)
x = abs(r2 - r1)
y = abs(c2 - c1)
if(x == 0 and y == 0):
    print(0)
    exit(0)
if(x + y <= 3 or x == y):
    print(1)
    exit(0)
if((x + y) % 2 == 0):
    print(2)
    exit(0)
if(abs(y - x) <= 3):
    print(2)
    exit(0)
if(x + y <= 6):
    print(2)
    exit(0)
for i in range(-2, 3):
    for j in range(-2, 3):
        nx = x + i
        ny = y + i
        if(nx == ny):
            print(2)
            exit(0)
if(x + 3 == y or x - 3 == y):
    print(2)
    exit(0)
print(3)
exit(0)
