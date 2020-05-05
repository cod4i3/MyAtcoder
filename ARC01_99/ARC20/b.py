n, c = map(int, input().split())
A, B = [], []
for i in range(n):
    a = int(input())
    if (i % 2): A.append(a)
    else: B.append(a)

l1, l2 = len(A), len(B)
n1, n2 = len(A), len(B)
for i in range(1, 11):
    if (l1 - A.count(i) >= l2 - B.count(i)):
        if (n2 > l2 - B.count(i)):
            n2 = min(n2, l2 - B.count(i))
        else:
            n1 = min(n1, l1 - A.count(i))
    elif (l2 - B.count(i) > l1 - A.count(i)):
        if(n1 > l1 - A.count(i)):
            n1 = min(n1, l1 - A.count(i))
        else:
            n2 = min(n2, l2 - B.count(i))

print(n1 * c + n2 * c)
