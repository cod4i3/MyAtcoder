import math
N = int(input())
T = [int(input()) for i in range(N)]
a = T[0]
for i in range(1, N):
    b = T[i]
    a = a * b // math.gcd(a, b)
print(a)
