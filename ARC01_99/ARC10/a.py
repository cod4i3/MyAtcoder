N, M, A, B = map(int, input().split())
c = [0] * M
for i in range(M):
    c[i] = int(input())
cnt = 1
for i in range(M):
    if (N <= A):
        N += B
    if (N < c[i]):
        print(cnt)
        exit(0)
    N -= c[i]
    cnt += 1
print('complete')
