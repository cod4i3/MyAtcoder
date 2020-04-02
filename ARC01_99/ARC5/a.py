N = int(input())
w = input().split()
list = ['TAKAHASHIKUN', 'Takahashikun', 'takahashikun']
w[-1] = w[-1][:-1]
cnt = 0
for i in range(N):
    if (w[i] in list): cnt += 1
print(cnt)
