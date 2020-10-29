N = input()
s = 0
for i in range(len(N)):
  s += int(N[i])
  s %= 9
if(s == 0): print('Yes')
else: print('No')