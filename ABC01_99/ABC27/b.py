N = int(input())
a = list(map(int, input().split()))
ave = sum(a) // N
if (len(a) == a.count(ave) or sum(a) == 0):
    print(0)
    exit(0)
if (sum(a) % N != 0):
    print(-1)
    exit(0)
cnt, ans = 0, 0
num, cur = 0, 0
for i in range(N):
    cur += a[i]
    num += 1
    if (num == 1):
        if (a[i] == ave):
            ans += cnt
            cnt = 0
        else:
            cnt += 1
    else:
        if (cur % num == 0 and cur // num == ave):
            ans += cnt
            cnt = 0
        else:
            cnt += 1

print(ans)
