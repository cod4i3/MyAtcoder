N = int(input())
A = list(map(int,input().split()))
print('NO') if(sum(A) % 2) else print('YES')