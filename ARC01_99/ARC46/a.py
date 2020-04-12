N = int(input())
l = []
for i in range(1, 10): l.append(i)
for i in range(11, 100, 11): l.append(i)
for i in range(111, 1000, 111): l.append(i)
for i in range(1111, 10000, 1111): l.append(i)
for i in range(11111, 100000, 11111): l.append(i)
for i in range(111111, 1000000, 111111): l.append(i)
print(l[N - 1])