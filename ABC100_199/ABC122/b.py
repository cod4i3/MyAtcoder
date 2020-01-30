s = input()
ans, sum = 0, 0
for i in range(len(s)):
    cur = s[i]
    if (cur == 'A' or cur == 'T' or cur == 'G' or cur == 'C'):
        sum += 1
    else: sum = 0
    ans = max(ans, sum)
print(ans)
