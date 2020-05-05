a, b, c = map(int, input().split())
A, B, C = a, b, c
ans = 0
if(a % 2 or b % 2 or c % 2):
    print(0)
    exit(0)
while(a % 2 == 0 and b % 2 == 0 and c % 2 == 0):
    if(A == B == C):
        ans = -1
        break
    A, B, C = a, b, c
    a = B // 2 + C // 2
    b = A // 2 + C // 2
    c = A // 2 + B // 2
    ans += 1
print(ans)
