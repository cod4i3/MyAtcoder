N = int(input())
list = [0] * 6
for i in range(N):
    t1, t2 = map(float, input().split())
    if (t1 >= 35): list[0] += 1
    if (35 > t1 >= 30): list[1] += 1
    if (30 > t1 >= 25): list[2] += 1
    if (t2 >= 25): list[3] += 1
    if (t2 < 0 and t1 >= 0): list[4] += 1
    if (t1 < 0): list[5] += 1
print(' '.join(map(str, list)))
