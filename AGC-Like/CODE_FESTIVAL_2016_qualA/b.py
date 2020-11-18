N = int(input())
a = list(map(int, input().split()))
for i in range(N): a[i] -= 1
ans = 0
for i in range(N): 
  if(a[a[i]] == i): ans += 1
print(ans//2)