C = int(input())
x, y, z = 0, 0, 0
for i in range(C):
    l = list(map(int, input().split()))
    l.sort()
    x, y, z = max(x, l[0]), max(y, l[1]), max(z, l[2])
print(x * y * z)
