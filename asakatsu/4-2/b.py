x, y = map(int, input().split())
A = []
while (x <= y):
    A.append(x)
    x *= 2
print(len(A))
