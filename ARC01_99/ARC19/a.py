l = ['O', 0, 'D', 0, 'I', 1, 'Z', 2, 'S', 5, 'B', 8]
s = input()
S = list(s)
for i in range(len(S)):
  for j in range(len(l)):
    if(S[i] == l[j] and j % 2 == 0):
      S[i] = str(l[j + 1])
print(''.join(S))
