N, Q = map(int, input().split())
a = [0] * N
for i in range(Q):
    l, r, t = map(int, input().split())
    for i in range(l - 1, r):
        a[i] = t
for i in range(N):
    print(a[i])