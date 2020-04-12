N, M = map(int, input().split())
A = list(map(int, input().split()))
A.sort(reverse=True)
print('No') if(A[M - 1] < sum(A) / (4 * M)) else print('Yes')
