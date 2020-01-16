n = int(input())
s = input()
ans = 0
for i in range(n):
    x, y = s[:i], s[i:]
    cnt = 0
    for j in range(26):
        if x.count(chr(ord('a') + j)) and y.count(chr(ord('a') + j)):
            cnt += 1
    ans = max(ans, cnt)
print(ans)
