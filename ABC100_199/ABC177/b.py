S = input()
T = input()
ans = 0
for i in range(len(S) - len(T) + 1):
    res = 0
    for j in range(len(T)):
        if(S[i + j] == T[j]): res += 1
    ans = max(res, ans)
print(len(T) - ans)
