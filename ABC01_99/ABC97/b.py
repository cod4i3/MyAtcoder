x = int(input())
seen = [0] * 1001
ans = 1
for i in range(x):
    if(seen[i]): pass
    cur = i
    if(i > 1):
        while (cur <= x):
            cur *= i
            if(cur <= x): ans = max(ans, cur)
print(ans)
