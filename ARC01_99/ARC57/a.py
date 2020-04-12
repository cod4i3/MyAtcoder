d = 0
A, K = map(int, input().split())
if (K == 0):
    print(2 * 10 ** 12 - A)
    exit(0)
while (A < 2 * 10 ** 12):
    A += 1 + K * A
    d += 1
print(d)