N = int(input())
p = list(map(int, input().split()))
p2 = p.copy()
p2.sort()
cnt = 0
for i in range(N):
    if (p[i] != p2[i]): cnt += 1
print('YES') if cnt == 0 or cnt == 2 else print('NO')
