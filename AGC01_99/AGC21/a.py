N = int(input())
S = str(N)
if(len(S) == 1): print(S); exit(0)
for i in range(1, len(S)):
    if(int(S[i]) != 9):
        print(int(S[0]) - 1 + (len(S) - 1) * 9)
        exit(0)
print(int(S[0]) + (len(S) - 1) * 9)
