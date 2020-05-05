N1, N2 = map(int, input().split())
A = set(map(int, input().split()))
B = set(map(int, input().split()))
mole, deno = 0, len(A) + len(B)
for a in A:
    if (a in B):
        mole += 1
        deno -= 1
print(mole / deno)
