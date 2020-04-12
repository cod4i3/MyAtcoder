N = int(input())
S = [input() for i in range(N)]
r, b = 0, 0
for i in range(N):
    r += S[i].count('R')
    b += S[i].count('B')
if (r > b): print('TAKAHASHI')
elif (b > r): print('AOKI')
else: print('DRAW')