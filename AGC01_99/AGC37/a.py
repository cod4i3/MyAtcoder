S = input()
if(len(S) < 3):
  if(S[0] == S[1] or S[1] == S[2]):
    print(2)
  else:
    print(1)
  exit(0)