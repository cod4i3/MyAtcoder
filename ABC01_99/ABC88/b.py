N = int(input())
A = list(map(int, input().split()))
alice, bob = 0, 0
while(True):
    alice += max(A)
    A.remove(max(A))
    if not A: break
    bob += max(A)
    A.remove(max(A))
    if not A: break
print(alice - bob)
