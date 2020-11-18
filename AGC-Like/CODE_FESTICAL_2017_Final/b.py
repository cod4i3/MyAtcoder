S = input()
l = ['a', 'b', 'c']

if(len(S) == 1):
  print('YES')
  exit(0)

if(len(S) == 2):
  if(S[0] == S[1]):
    print('NO')
  else:
    print('YES')
  exit(0)

for i in range(3):
  if(S.count(l[i]) < len(S)//3):
    print('NO')
    exit(0)
a, b, c = S.count('a'), S.count('b'), S.count('c')
if(abs(a - b) > 1 or abs(b - c) > 1 or abs(c - a) > 1): print('NO')
else: print('YES')