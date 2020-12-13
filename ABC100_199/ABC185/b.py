N, M, T = map(int, input().split())
A, B = [0] * M, [0] * M
for i in range(M):
    A[i], B[i] = map(int, input().split())
res = N
for i in range(M):
    if(i == 0): N -= A[0]
    else: N -= A[i] - B[i - 1]
    if(N <= 0):
        print('No')
        exit(0)
    N += B[i] - A[i]
    if(N >= res): N = res
N -= T - B[-1]
print('Yes') if(N > 0) else print('No')
