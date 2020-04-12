A, B, C, K = map(int, input().split())
S, T = map(int, input().split())
print(S * A + T * B) if(S + T < K) else print(S * A + T * B - (S + T) * C)