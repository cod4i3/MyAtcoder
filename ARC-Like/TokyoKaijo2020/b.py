A, V = map(int, input().split())
B, W = map(int, input().split())
T = int(input())

# 相対速度、距離
S = V - W
D = abs(A - B)
if(D > S * T):
    print('NO')
    exit(0)
else:
    print('YES')
