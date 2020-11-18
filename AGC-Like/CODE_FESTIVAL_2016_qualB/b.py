N, A, B = map(int, input().split())
S = input()
res, all = 0, 0
for i in range(N):
  if(S[i] == 'c'):
    print('No')
  elif(all >= A + B):
    print('No')
  elif(S[i] == 'b'):
    if(res < B): 
      print('Yes')
      all += 1
    else: print('No')
    res += 1
  else:
    print('Yes')
    all += 1