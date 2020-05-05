def gcd(a, b, cnt):
    if (b == 0): return cnt
    cnt += 1
    return gcd(b, a % b, cnt)


# ユークリッドを遡ればいい
K = int(input())

cnt = 0
a, b, c = 0, 1, 0
while (cnt != K):
    a = b + c
    b, c = a, b
    cnt += 1
a = b + c
print(a, b) if(K != 1) else print(1, 1)
