s = input()
r = s[::-1]
for i in range(len(s)):
    if((len(s) % 2 and i == len(s) // 2 + 1) or s[i] == r[i] or r[i] == '*' or s[i] == '*'): pass
    else:
        print('NO')
        exit(0)
print('YES')