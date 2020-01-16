s = input(); t = input()
for i in range(len(s)):
  if (s[i: len(s)] + s[:i] == t):
    print('Yes')
    exit(0)
print('No')
