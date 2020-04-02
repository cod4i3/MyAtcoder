from math import sqrt
N = int(input())
for i in range(2, int(sqrt(N)) + 1):
    if (N % i == 0):
        print('NO')
        exit(0)
print('YES')