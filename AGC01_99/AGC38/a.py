H, W, A, B = map(int, input().split())
s = '1' * A + '0' * (W - A)
ans = [""] * H
pad = 1
if(A != 0 and A != 1 and W % A == 0): pad = W // A
for i in range(H):
    str = s[(i * pad) % W:] + s[:(i * pad) % W]
    ans[i] = str
for i in range(W):
    str = ""
    for j in range(H):
        str += ans[j][i]
    cnt = min(str.count('1'), str.count('0')) 
    if(cnt != B):
      print('No')
      exit(0)
for i in range(H):
  print(ans[i])
