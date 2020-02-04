N, K, Q = map(int, input().split())
A = [int(input()) for i in range(Q)]
P = [0] * N
for i in range(Q):
    P[A[i] - 1] += 1
for i in range(N):
    if (K - (Q - P[i]) <= 0): print('No')
    else: print('Yes')
