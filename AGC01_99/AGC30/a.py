A, B, C = map(int, input().split())
if(A + B >= C - 1):
    print(B + C)
    exit(0)
ans = 0
ans, C = 2 * B, C - B
ans += (C if(A >= C - 1) else A + 1)
print(ans)