S, T = input().split()
A, B = map(int, input().split())
U = input()
print(A,B-1) if(U == T) else print(A-1, B)