S = input()
A = list(map(int, input().split()))
for i in range(len(S)):
    if (i in A): print('"', end="")
    print(S[i], end="")
if(len(S) in A): print('"', end="")
print()