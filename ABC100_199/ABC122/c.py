N, Q = map(int, input().split())
S = input()
l, r = [0] * Q, [0] * Q
cnt = [0] * len(S)
for i in range(Q):
    l[i], r[i] = map(int, input().split())
    l[i] -= 1
    r[i] -= 1
for i in range(1, len(S)):
    if(i == 0): pass
    cnt[i] = cnt[i - 1]
    if (S[i] == 'C' and S[i - 1] == 'A'):
        cnt[i] += 1
for i in range(Q):
    print(cnt[r[i]] - cnt[l[i]])
