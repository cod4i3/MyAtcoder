S = input()
ans = len(S)
cntS = 0
for i in range(len(S)):
    if (S[i] == 'S'):
        cntS += 1
    else:
        if (cntS > 0):
            cntS -= 1
            ans -= 2
        else: cntS = 0
print(ans)