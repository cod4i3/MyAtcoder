def Yes(): print('Yes'); exit(0)
def No(): print('No'); exit(0)


N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
if(sum(a) > sum(b)): No()
if(sum(a) == sum(b) and a != b): No()
if(a == b): Yes()
c = [b[i] - a[i] for i in range(N)]
print(c)
p = sum([e for e in c if e > 0])
m = sum([-e for e in c if e < 0])
Yes() if(p < 2 * m) else No()
