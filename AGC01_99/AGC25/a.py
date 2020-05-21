N = int(input())
if(not N % 10):
    print(10)
    exit(0)
ans = 0
while(N > 0):
    ans += N % 10
    N //= 10
print(ans)
