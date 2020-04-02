N, M = map(int, input().split())
disk = [(i + 1) for i in range(N)]
have, tmp = 0, 0
for i in range(M):
    d = int(input())
    for j in range(len(disk)):
        if (disk[j] == d):
            tmp = disk[j]
            disk[j] = have
            have = tmp

for i in range(len(disk)):
    print(disk[i])
