N, M, K = map(int, input().split())

for i in range(N + 1):
    for j in range(M + 1):
      if(i * M - j * i + j * (N - i) == K):
        print('Yes')
        exit(0)
print('No')
