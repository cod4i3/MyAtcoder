N = int(input())
A, B = map(int, input().split())
P = list(map(int, input().split()))
l1, l2, l3 = [], [], []
for i in range(len(P)):
  if(P[i] <= A): l1.append(P[i])
  elif(P[i] <= B): l2.append(P[i])
  else: l3.append(P[i])
print(min(len(l1), len(l2), len(l3)))