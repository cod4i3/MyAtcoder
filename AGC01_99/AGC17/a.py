N, P = map(int, input().split())
A = list(map(int, input().split()))
for i in range(N): A[i] %= 2
zero, one = A.count(0), A.count(1)
if(one == 0 and P == 1):
    print(0)
elif(one == 0 and P == 0):
    print(2 ** N)
else:
    print(2 ** (N - 1))
