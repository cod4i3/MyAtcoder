int(input())
print(sum(map(lambda a: format(int(a), 'b')[::-1].index('1'), input().split())))