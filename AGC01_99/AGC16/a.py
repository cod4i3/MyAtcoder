s = input()
ans = 100
for i in range(26):
    cur = 0
    c = chr(ord('a') + i)
    t = s
    if(not c in t): continue
    t2 = ""
    while(t.count(c) != len(t)):
        for j in range(len(t) - 1):
            if(t[j] == c or t[j + 1] == c):
                t2 += c
            else:
                t2 += 'A'
        cur += 1
        t = t2
        t2 = ""
    ans = min(cur, ans)
print(ans)
