K, A, B = map(int, input().split())
if(B <= A + 2): 
  print(K + 1)
  exit(0)

if(1 + K < A + 1):
  print(K + 1)
  exit(0)

ans = 1
K -= A - 1
ans += A - 1
K -= 1
ans -= A
K -= 1
ans += B

ans += (K//2) * B
ans -= (K//2) * A
K %= 2
ans += K
print(ans)