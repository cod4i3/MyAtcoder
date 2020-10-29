A = list(map(int, input().split()))
S = sum(A)
if(S % 2):
    print('No')
    exit(0)
flag = False
for i in range(2 ** 4):
    res = 0
    if(i ^ 8): res -= A[0]
    if(res == S // 2): flag = True
    if(i ^ 4): res -= A[1]
    if(res == S // 2): flag = True
    if(i ^ 2): res -= A[2]
    if(res == S // 2): flag = True
    if(i ^ 1): res -= A[3]
    if(res == S // 2): flag = True
print('Yes') if flag else print('No')
