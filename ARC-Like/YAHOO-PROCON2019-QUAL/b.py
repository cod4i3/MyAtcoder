c = [list(map(int, input().split())) for _ in range(3)]
ans = [0] * 4
for e in c:
  ans[e[0] - 1] += 1
  ans[e[1] - 1] += 1

for i in range(len(ans)):
  if(ans[i] == 0 or ans[i] == 3):
    print('NO')
    exit(0)
print('YES')