N = int(input()) 
A, B = map(int, input().split())
# 0から2回行動でまとめて(A + 1)ずつ加えることを考える（N個目置いた方が勝ち）
# 途中でNまで残り (A + B) 個という場面になる(B > A)
# ここから B = 1なら(B - 1)個置いて奇数番の勝ち、 B != 1なら偶数番の勝ち
# つまりN % (A + 1) を計算すればいい
if(A == B):
  if(N % (A + 1) == 0):
    print('Aoki')
  else:
    print('Takahashi')
  exit(0)

if(A > B):
  print('Takahashi')

if(A < B):
  if(N <= A):
    print('Takahashi')
  else:
    print('Aoki')