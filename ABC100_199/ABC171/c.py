N = int(input()) - 1
al = [chr(ord('a') + i % 26) for i in range(26)]

ans = ""
while(N >= 0):
    ans += al[N % 26]
    N //= 26
    N -= 1

ans = ans[::-1]
print(ans)
