S = input()
flag = True
for c in S:
    if S.count(c) != 2:
        flag = False
print('Yes') if flag else print('No')
