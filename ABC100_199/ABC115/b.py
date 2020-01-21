N = int(input())
P = [int(input()) for i in range(N)]
print(int(sum(P) - max(P) / 2))
