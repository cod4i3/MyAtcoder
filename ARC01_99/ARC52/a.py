S = list(input())
n = 0
for i in range(len(S)):
    if (S[i].isdigit()):
        if(i != len(S) - 1):
            if (S[i + 1].isdigit()):
                n = int(S[i]) * 10 + int(S[i + 1])
            else:
                n = int(S[i])
            break
        else: n = int(S[i])
print(n)
