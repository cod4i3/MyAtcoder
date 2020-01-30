a = [0] * 5
for i in range(5):
    a[i] = int(input())
k = int(input())
if (max(a) - min(a) > k): print(":("); exit(0)
print('Yay!')
