N = int(input())
L = list(map(int, input().split()))
ans = 0
for i in range(N - 2):
    for j in range(i + 1, N - 1):
        for k in range(j + 1, N):
            a, b, c = L[i], L[j], L[k]
            S = a + b + c
            M = max(a, max(b, c))
            if(M < S - M
              and a != b
              and b != c
              and c != a):
                ans += 1

print(ans)
