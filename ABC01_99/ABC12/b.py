N = int(input())
print(format(N // 3600, '02'), format((N % 3600) // 60, '02'), format(N % 60, '02'), sep=":")