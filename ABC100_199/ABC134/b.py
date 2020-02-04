from math import ceil
N, D = map(int, input().split())
print(ceil(N / (D * 2 + 1)))