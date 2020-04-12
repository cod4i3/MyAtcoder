S = input().split()
for i in range(len(S)):
    if (S[i] == 'Left'): S[i] = '<'
    if (S[i] == 'Right'): S[i] = '>'
    if (S[i] == 'AtCoder'): S[i] = 'A'
print(' '.join(S))
