S = input()
N = len(S)
if(N == 1):
    print(1)
    exit(0)
if(N == 2):
    if(S[0] == S[1]): print(1)
    else: print(2)
    exit(0)
l = []
l.append(S[0])
C = ""
for i in range(1, N):
    C += S[i]
    if(C != l[-1]):
        l.append(C)
        C = ""
print(len(l))
