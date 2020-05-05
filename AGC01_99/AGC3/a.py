def c(S, a):
    return S.count(a)


S = input()
n, w, s, e = c(S, 'N'), c(S, 'W'), c(S, 'S'), c(S, 'E')
if ((n > 0 and s == 0) or (s > 0 and n == 0)):
    print('No')
elif ((w > 0 and e == 0) or (e > 0 and w == 0)):
    print('No')
else:
    print('Yes')
