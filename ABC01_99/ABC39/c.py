S = input()
l = ['Do', 'Re', 'Mi', 'Fa', 'So', 'La', 'Si']
ans = "WBWBWWBWBWBW"
if (S == ans[:] + ans[:8]):
    print(l[0])
if (S == ans[2:] + ans[:10]):
    print(l[1])
if (S == ans[4:] + ans):
    print(l[2])
if (S == ans[5:] + ans + ans[:1]):
    print(l[3])
if (S == ans[7:] + ans + ans[:3]):
    print(l[4])
if (S == ans[9:] + ans + ans[:5]):
    print(l[5])
if (S == ans[11:] + ans + ans[:7]):
    print(l[6])
