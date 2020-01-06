import sys
x, y = map(int, input().split())
list1 = [1, 3, 5, 7, 8, 10, 12]
list2 = [4, 6, 9, 11]
if x == 2 or y == 2:
    print('Yes') if x == y else print('No')
    sys.exit()

print('Yes') if list1.count(x) != list2.count(y) else print('No')
