N, A, B = map(int, input().split())
if (A == 0):
    print(0)
    exit(0)
if (B == 0):
    print(N)
    exit(0)
l = A + B
C = N // l
print(A * C + min(A, (N - (l * C))))