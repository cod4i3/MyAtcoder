S = [input() for _ in range(12)]
ans = 0
for i in range(12):
    if (S[i].count('r')): ans += 1
print(ans)