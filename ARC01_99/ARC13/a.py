L, M, N = map(int, input().split())
P, Q, R = map(int, input().split())
if(R > N): print(0); exit(0)
a = ((N // R) * max((M // Q) * (L // P), (M // P) * (L // Q)))
b = ((N // P) * max((M // Q) * (L // R), (M // R) * (L // Q)))
c = ((N // Q) * max((M // P) * (L // R), (M // R) * (L // P)))
print(max(a, b, c))