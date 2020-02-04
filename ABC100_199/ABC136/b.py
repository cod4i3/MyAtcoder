ans = 0
for i in range(1, int(input()) + 1):
    cur, cnt = i, 0
    while (cur):
        cur //= 10
        cnt += 1
    if (cnt % 2 == 1):
        ans += 1
print(ans)
