N = int(input())
d = [int(input()) for i in range(N)]
d.sort()
cnt, cur = 0, 0
for i in d:
    if(i != cur):
        cur = i
        cnt += 1
print(cnt)
