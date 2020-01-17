s = input()
k = int(input())
first = len(s)
for i in range(len(s)):
  if s[i] != '1': first = i; break
if s[0] != '1': print(s[0]); exit(0)
print(1) if k <= first else print(s[first])
