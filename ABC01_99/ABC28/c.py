A = list(map(int, input().split()))
ans = []
for i in range(3):
    for j in range(i + 1, 4):
        for k in range(j + 1, 5):
            ans.append(A[i] + A[j] + A[k])
ans.sort(reverse=True)
print(ans[2])