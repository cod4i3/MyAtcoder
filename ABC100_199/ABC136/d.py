S = input()
N = len(S)
r, l = 0, 0
cnt = 0
ans = [0] * N
for i in range(N):
    if (S[i] == 'R'):
        cnt += 1
    if (S[i] == 'L' and S[i - 1] == 'R'):
        ans[i - 1] = cnt
        cnt = 0
print(range(N - 1, -1, -1))
for i in range(N - 1, -1, -1):
    if (S[i] == 'L'):
        cnt += 1
    if (S[i] == 'R' and S[i + 1] == 'L'):
        ans[i + 1] = cnt
        cnt = 0
print(ans)
for i in range(N - 1):
    if (ans[i] > 0 and ans[i + 1] > 0):
        a = (ans[i] + ans[i + 1]) // 2
        if((ans[i] + ans[i + 1]) % 2):
            if (ans[i] > ans[i + 1]):
                sw = ans[i]
                ans[i] = a + 1
                ans[i + 1] = a
                if (sw % 2 == 0):
                    ans[i], ans[i + 1] = ans[i + 1], ans[i]
            else:
                sw = ans[i + 1]
                ans[i] = a
                ans[i + 1] = a + 1
                if (sw % 2 == 0):
                    ans[i], ans[i + 1] = ans[i], ans[i + 1]

        else:
            ans[i], ans[i + 1] = a, a
        print(i)

answer = [str(ans[i]) for i in range(len(ans))]
print(" ".join(answer))
