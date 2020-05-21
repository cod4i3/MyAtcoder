S = input()
T = input()
l = len(T)
print('Yes') if S == T[:l - 1] else print('No')