def Yes(): print('Yes'); exit(0)
def No(): print('No'); exit(0)


N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = [b[i] - a[i] for i in range(N)]
p = [e//2 for e in c if e > 0]
m = [-e for e in c if e < 0]
if(sum(p) >= 2 * sum(m)): Yes()
else: No()
