N = int(input())
a, b = [0] * N,[0] * N
ans = 0
for i in range(N):
  a[i],b[i] = map(int, input().split())
  ans += a[i] * b[i]
print(int(ans * 1.05))
