N = int(input())
a, b = map(int, input().split())
K = int(input())
P = list(map(int, input().split()))
if (P.count(a) or P.count(b)):
    print('NO')
    exit(0)
for i in range(K):
    if (P.count(P[i]) >= 2):
        print('NO')
        exit(0)
print('YES')