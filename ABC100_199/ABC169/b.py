N = int(input())
A = list(map(int, input().split()))
A.sort()
ans = A[0]
for i in range(1, N):
    ans *= A[i]
    if(ans > 10**18):
        print(-1)
        exit(0)
print(ans)
