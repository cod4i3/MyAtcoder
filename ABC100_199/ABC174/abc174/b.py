N, D = map(int, input().split())
ans = 0
for i in range(N):
    X, Y = map(int, input().split())
    if(D**2 >= X**2 + Y**2): ans += 1
print(ans)
