H, A = map(int, input().split())
print(H // A + 1) if H % A != 0 else print(H // A)
