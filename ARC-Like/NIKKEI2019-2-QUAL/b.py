def rep_pow(x, n):
    ans, MOD = 1, 998244353
    while n:
        if n % 2:
            ans *= x
            ans %= MOD
        x *= x
        x %= MOD
        n >>= 1
    return ans


N = int(input())
D = list(map(int, input().split()))
MOD = 998244353
from collections import Counter
cnt = Counter(D)
if(cnt[0] != 1 or D[0] != 0):
  print(0)
  exit(0)
ans = 1
for i in range(1, len(cnt)):
    ans *= rep_pow(cnt[i - 1],cnt[i])
    ans %= MOD
    if(ans == 0): break
print(ans)
