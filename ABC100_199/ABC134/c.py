N = int(input())
A = list(int(input()) for i in range(N))
MAX = int(max(A))
B = A.copy()
B.sort()
for i in range(N):
    if (A[i] == MAX): print(B[N - 2])
    else: print(MAX)
