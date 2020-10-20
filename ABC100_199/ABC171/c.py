N = int(input())
al2 = [chr(ord('a') + (ord('z') - ord('a') + i) % 26) for i in range(26)]
al = [chr(ord('a') + i % 26) for i in range(26)]

print(al)
ans = ""
while(N):
    cur = N % 26
    if(N <= 26):
        ans += al[N - 1]
        break
    N //= 26
    ans += al[cur - 1]
    print(N, cur)
print(ans[::-1])
