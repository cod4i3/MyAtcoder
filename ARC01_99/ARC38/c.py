N = int(input())
S = input()
l = ['R', 'G', 'B']
ans = 0
for i in range(3):
  ans += S.count(l[i]) % 2
print(ans)