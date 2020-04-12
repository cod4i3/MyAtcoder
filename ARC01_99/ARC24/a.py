L, R = map(int, input().split())
l = list(map(int, input().split()))
r = list(map(int, input().split()))
ans = 0
for i in range(L):
    for j in range(len(r)):
        if (l[i] == r[j]):
            ans += 1
            r.pop(j)
            break
print(ans)