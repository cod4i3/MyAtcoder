from math import *
S = input()
ans = [0] * len(S)
cur_r = True
l, s = 0, 0
for i in range(len(S)):
    if(cur_r):
        if S[i] == 'R': l += 1
        else:
            ans[i - 1] += ceil(l / 2)
            ans[i] += floor(l / 2)
            l, s = 1, i
            cur_r = False
    else:
        if(S[i] == 'L'): l += 1
        else:
            ans[s] += ceil(l / 2)
            ans[s - 1] += floor(l / 2)
            l, s = 1, i
            cur_r = True
ans[s] += ceil(l / 2)
ans[s - 1] += floor(l / 2)
print(' '.join(str(n) for n in ans))
