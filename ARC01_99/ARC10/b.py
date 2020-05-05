import datetime
from datetime import datetime
from datetime import timedelta
N = int(input())
dt_1 = datetime(2011, 12, 31)
li = [[0, 0] for i in range(N)]
m, d = [0] * N, [0] * N
li.sort()
for i in range(N):
    m[i], d[i] = map(int, input().split('/'))
    dt_holi = datetime(2012, m[i], d[i])
    while ((dt_holi - dt_1).days % 7 == 0 or (dt_holi - dt_1).days % 7 == 1 or [dt_holi.month, dt_holi.day] in li):
        dt_holi += timedelta(days=1)
    if (dt_holi.year == 2012):
        li[i] = [dt_holi.month, dt_holi.day]

holiday, ans = 0, 2
for i in range(366):
    dt_2 = datetime(2012, 1, 1) + timedelta(days=i)
    dt_diff = dt_2 - dt_1
    if (dt_diff.days % 7 == 0 or dt_diff.days % 7 == 1):
        holiday += 1
    elif ([dt_2.month, dt_2.day] in li):
        holiday += 1
    else:
        holiday = 0
    ans = max(ans, holiday)

print(ans)
