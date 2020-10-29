S = input()
if(S[1] == 'S'):
  if(S[0] == 'R' or S[2] == 'R'):
    print(1)
  else:
    print(0)

else:
  if(S[0] == 'R' and S[2] == 'R'):
    print(3)
  elif(S[0] == 'R' or S[2] == 'R'):
    print(2)
  else:
    print(1)