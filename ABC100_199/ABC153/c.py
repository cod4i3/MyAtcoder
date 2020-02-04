N, K = map(int, input().split())
H = list(map(int, input().split()))
H.sort(reverse=True)
for i in range(K):
    H[i] = 0
    if(i == N - 1): break
print(sum(H))
