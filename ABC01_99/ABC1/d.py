N = int(input())
SE = []
for i in range(N):
    l = list(map(int, input().split('-')))
    SE.append(l)


for i in range(N):
    SE[i][0] = (SE[i][0] // 5) * 5
    if(SE[i][1] % 5):
        SE[i][1] = (SE[i][1] // 5 + 1) * 5
        if(SE[i][1] % 100 == 60):
            SE[i][1] += 40
    else:
        SE[i][1] = (SE[i][1] // 5) * 5

if(N == 1):
    print("{}-{}".format(str(SE[0][0]).zfill(4), str(SE[0][1]).zfill(4)))
    exit(0)


SE.sort()
for i in range(N):
    SE[i].sort()

SE.append([100000, 1000000])
s, e = SE[0][0], SE[0][1]
ans = []
for i in range(1, N + 1):
    if(s <= SE[i][0] <= e):
        e = max(SE[i][1], e)
    else:
        ans.append([s, e])
        s, e = SE[i][0], SE[i][1]

ans.sort()
for i in range(len(ans)):
    print("{}-{}".format(str(ans[i][0]).zfill(4), str(ans[i][1]).zfill(4)))
