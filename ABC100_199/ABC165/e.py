N, M = map(int, input().split())
seen = [False] * (N + 1)
for i in range(M):
    if(N % 2): print(i + 1, N - i)
    else:
        l, r = i + 1, N - 1
        if(seen[r - l + 1] == False and seen[N - r + 1 + l] == False):
            print(i + 1, (N - i))
            seen[r - l + 1], seen[N - r + 1 + l] = True, True
        else: print(i + 1, N // 2)
