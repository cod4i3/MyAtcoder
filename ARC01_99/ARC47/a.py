N, L = map(int, input().split())
S = input()
t, c = 1, 0
for i in range(N):
    if (S[i] == '+'): t += 1
    elif (t > 1): t -= 1
    else: pass
    if (t > L):
        t = 1
        c += 1
print(c)