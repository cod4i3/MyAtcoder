H, W = map(int, input().split())
S = [list(input().split()) for i in range(H)]
for i in range(H):
  for j in range(W):
    if(S[i][j] == 'snuke'): 
      print("{}{}".format(chr(ord('A') + j), i+1))
      exit(0)