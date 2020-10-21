N = int(input())
al = [chr(ord('a') + i % 26) for i in range(26)]

ans = ""
digit = 0
n = N
# 桁数調べ
while(n):
    n //= 27
    digit += 1
print(digit)

while(N):
    n = 1
    while(n * 27 <= N):
        n *= 27
    '''
    print("27 ^ %d = %d" %(digit-1, 27**digit))
    digit -= 1
    print("%d * %d = %d" %(n, N//n, (N//n)*n))
    ''' 
    ans += al[N // n - 1]
    print((N//n)*n, N-(N//n)*n, (N//n)*n + (N-(N//n)*n), N)
    N -= (N//n)*n
print(ans)
