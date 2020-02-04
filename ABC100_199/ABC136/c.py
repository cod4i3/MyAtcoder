N = int(input())
H = list(map(int, input().split()))
MAX = 0
for i in range(N):
    MAX = max(MAX, H[i])
    if (H[i] <= MAX - 2):
        print('No')
        exit(0)
print('Yes')