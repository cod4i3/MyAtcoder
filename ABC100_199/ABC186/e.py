def main():
    from math import gcd
    T = int(input())
    ans = [0] * T

    # Kx + S ≡ 0 (modN)
    # Kx ≡ -S (modN)となる最小のxを求める
    # kx + Ny = -S となる最小のxを求める
    for i in range(T):
        N, S, K = map(int, input().split())
        d = gcd(N, gcd(S, K))
        N, S, K = N // d, S // d, K // d
        D = gcd(K, N)
        # ax + by ≡ c において、c ≢ gcd(a, b)
        # 仮に割り切れているなら, aとbは互いに素(a ⊥ b)
        # かつ、c = gcd(a, b) より c = 1
        if(D != 1):
            ans[i] = -1
            continue
        # この時点で、 
        # Kx ≡ -S (modN) は
        # K'x ≡ 1 (mod N') となっている 
        if(D == 1):
            ans[i] = (-S * pow(K, -1, N)) % N
    for i in range(T):
        print(ans[i])

if __name__ == "__main__":
    main()
