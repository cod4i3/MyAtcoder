n, k = map(int, input().split())
s = input()
print(s[:k - 1] + chr(ord(s[k - 1]) - ord('A') + ord('a')) + s[k:])
