from math import floor
A, B = map(int, input().split())
N = -1
for i in range(1, 1000):
  if (floor(i * 0.08) == A and floor(i * 0.10) == B):
    print(i)
    exit(0)
print(N)
