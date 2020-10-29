N, K, S = map(int, input().split())
if K == 0: A = [735477] * N; print(*A); exit(0)
if N == K: A = [S] * K; print(*A); exit(0)
if N == 1: print(S); exit(0)
if N == 2:
    if (S % 2 == 0): print(int(S / 2), int(S / 2)); exit(0)
    if (S % 2 == 1): print(int(S / 2), int(S / 2 + 1)); exit(0)
if S == 1:
    A = [1] * K
    for i in range(N - len(A)): A.append(735477)
    print(*A)
    exit(0)
if S % 2 == 0:
    A = [int(S / 2)] * (K + 1)
    for i in range(N - len(A)): A.append(735477)
    print(*A)
else:
    if(K % 2 == 0):
        A = [int(S / 2), int(S / 2) + 1] * int(K / 2)
        A.append(int(S / 2))
        for i in range(N - len(A)): A.append(735477)
        print(*A)
    else:
        A = [int(S / 2), int(S / 2) + 1] * int(K / 2 + 1)
        for i in range(N - len(A)): A.append(735477)
        print(*A)
