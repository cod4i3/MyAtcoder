M, D = map(int, input().split())
ans = 0
for i in range(M + 1):
    for j in range(D + 1):
        if(i < 3 or j // 10 < 2 or j % 10 < 2):
            continue
        if(i == (j // 10) * (j % 10)): ans += 1
print(ans)
