N, A, B = map(int, input().split())
while (True):
    N -= A
    if (N <= 0): print('Ant'); exit(0)
    N -= B
    if (N <= 0): print('Bug'); exit(0)
