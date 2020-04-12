s = list(input())
ans = ""
cur = s[0]
for i in range(1, len(s)):
    if (s[i] == cur[0]):
        cur += s[i]
    else:
        ans += cur[0] + str(len(cur))
        cur = s[i]
ans += cur[0] + str(len(cur))
print(ans)