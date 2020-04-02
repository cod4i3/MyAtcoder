from math import ceil
tv = input() * 2
o, x, cnt_o, cnt_x = 1, 1, 0, 0
for i in range(1, len(tv)):
    if (tv[i] == tv[i - 1]):
        if (tv[i] == 'o'): cnt_o += 1
        else: cnt_x += 1
        o, x = max(o, cnt_o), max(x, cnt_x)
    else: cnt_o = cnt_x = 1
if(not tv.count('x')): print(1)
else: print(ceil(x / o) + 1)
