N = int(input())
A = list(map(int, input().split()))
ans, cnt = 0, 0
while (True):
    cnt = ans
    for i in range(N):
        if(A[i] % 2 == 1): break
        A[i] //= 2
        if (i == N - 1): ans += 1
    if (cnt == ans): break
print(ans)
