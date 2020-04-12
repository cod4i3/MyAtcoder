N = int(input())
s = [input() for i in range(N)]
for i in range(N):
    for j in range(N - 1, -1, -1):
        print(s[j][i], end="")
    print()