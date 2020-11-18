s = input()
C, F = False, False
for i in range(len(s)):
  if(C and s[i] == 'F'):
    F = True
    break
  if(s[i] == 'C'): C = True
print('Yes') if(C and F) else print('No')