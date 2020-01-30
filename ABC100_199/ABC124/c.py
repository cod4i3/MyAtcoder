S = input()
cnt01, cnt10 = 0, 0
for i in range(len(S)):
    if (i % 2 == 0):
        if (S[i] == '1'): cnt01 += 1
        else: cnt10 += 1
    else:
        if (S[i] == '1'): cnt10 += 1
        else: cnt01 += 1
print(min(cnt01, cnt10))
