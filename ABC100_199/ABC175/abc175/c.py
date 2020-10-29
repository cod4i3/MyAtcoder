X, K, D = map(int, input().split())
if(K * D < abs(X)):
  print(abs(X) - K * D)
  exit(0)

X = abs(X)
K -= X//D
X -= D * (X//D)
if(K % 2 == 0):
  print(X)
else:
  print(D - X)
