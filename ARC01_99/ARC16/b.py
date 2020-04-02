N = int(input())
X = [""] * N
cnt = 0
for i in range(N):
    X[i] = input()
    for j in range(9):
        if (X[i][j] == 'o'):
            if (i >= 1 and X[i - 1][j] == 'o'): continue
            else: cnt += 1
        if(X[i][j] == 'x'): cnt += 1
print(cnt)