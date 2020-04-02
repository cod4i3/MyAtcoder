W = input()
list = ['a', 'i', 'u', 'e', 'o']
ans = ''
for i in range(len(W)):
  flag = True
  for j in range(len(list)):
    if(W[i] == list[j]): flag = False
  if(flag): ans += W[i]
print(ans)
