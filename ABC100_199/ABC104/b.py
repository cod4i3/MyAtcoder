import re
s = input()
cnt = 0
if (s[2:-1].count('C') != 1):
    print('WA')
    exit(0)
for i in range(len(s)):
    if (s[i] >= 'A' and s[i] <= 'Z'):
        cnt += 1
        if (cnt >= 3):
            print('WA')
            exit(0)
print('AC') if s[0]=='A' else print('WA')
