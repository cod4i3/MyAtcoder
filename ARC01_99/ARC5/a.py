N = int(input())
w = [input() for _ in range(N)]
list = ['TAKAHASHIKUN', 'Takahashikun', 'takahashikun']
cnt = 0
for i in range(N):
  if (w[i] in list): cnt += 1
print(cnt)