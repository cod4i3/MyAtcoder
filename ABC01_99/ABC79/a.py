N = input()
cnt = 0
for i in range(len(N) - 1): cnt += (N[i] == N[i + 1])
print('Yes') if cnt >= 2 and N[1]==N[2] else print('No')
