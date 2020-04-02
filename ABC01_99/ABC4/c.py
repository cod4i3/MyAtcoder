N = int(input())
list = [1, 2, 3, 4, 5, 6]
ans = []
for i in range((N // 5) % 6, len(list)):
    ans.append(list[i])
for i in range((N // 5) % 6):
    ans.append(list[i])
for i in range(N % 5):
    ans[i], ans[i + 1] = ans[i + 1], ans[i]
print(*ans, sep="")
