from math import ceil
A, B, K, L = map(int, input().split())
print(min((K % L) * A + K // L * B, ceil(K / L) * B))