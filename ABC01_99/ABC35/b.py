S = input()
T = int(input()) - 1
n = abs(S.count('L') - S.count('R')) + abs(S.count('U') - S.count('D'))
t = S.count('?')
if(T):
    if (n >= t): print(n - t)
    else: print(abs(t - n) % 2)
else:
    print(n + t)
