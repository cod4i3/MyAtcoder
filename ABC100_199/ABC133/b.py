from math import sqrt
N, D = map(int, input().split())
X = [list(map(int, input().split())) for i in range(N)]
ans = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        dis = 0
        for k in range(D):
            dis += (X[i][k] - X[j][k]) ** 2
        dis = sqrt(dis)
        if (dis % 1 == 0): ans += 1
print(ans)
