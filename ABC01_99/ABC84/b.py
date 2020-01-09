a, b = map(int, input().split())
s = input()
flag = True
if (s[a] != '-'): flag = False
for i in range(a + b - 1):
    if (i == a): pass
    elif s[i] == '-': flag = False
print('Yes') if flag else print('No')
