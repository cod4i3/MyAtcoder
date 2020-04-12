N = int(input())
c = input()
ans = []
for i in range(4):
  ans.append(c.count(str(i + 1)))
print(max(ans), min(ans))