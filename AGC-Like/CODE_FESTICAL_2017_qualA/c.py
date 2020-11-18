def NO():
  print("No")
  exit(0)

def YES():
  print("Yes")
  exit(0)


H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]

l = [0] * 26
for i in range(H):
    for j in range(W):
        l[ord(a[i][j]) - ord('a')] += 1

l = [e for e in l if e != 0]

one, two, four = 0, 0, 0
S, N = H * W, len(l)

if(H % 2 == 0 and W % 2 == 0):
    for i in range(N):
        if(l[i] % 4): NO()
    YES()

cnt = [0] * 4
if(S % 2 == 1):
    for i in range(N): cnt[l[i] % 4] += 1
    if(cnt[3]): NO()
    if(cnt[1] != 1): NO()
    if(cnt[2] > (H//2) + (W//2)): NO()
    YES()

if(W % 2): H, W = W, H
for i in range(4): cnt[i] = 0

for i in range(N): cnt[l[i] % 4] += 1
if(cnt[1] or cnt[3]): NO()
if(cnt[2] > W//2): NO()
YES()
