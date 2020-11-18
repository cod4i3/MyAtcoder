S = input()
if(len(S) > 9): print('NO'); exit(0)
l = ['KIHBR', 'KIHABR', 'KIHBAR', 'KIHABAR']
for i in range(4):
  if(S.count(l[i]) and not S.count('AA')):
    print('YES')
    exit(0)
print('NO')