s = input()
ans = []
for c in s:
  if(c == 'B'):
    if(len(ans) != 0): ans.pop()
  else:
    ans.append(c)
print(''.join(ans))