def f(x, y, z):
    n = x**2 + y**2 + z**2 + x * y + y * z + z * x
    return n


def main():
    N = int(input())
    ans = [0] * 10500
    for x in range(1, 100):
        for y in range(1, 100):
            for z in range(1, 100):
                if(f(x, y, z) >= 10010): continue
                ans[f(x, y, z)] += 1

    for i in range(1, N + 1):
        print(ans[i])


if __name__ == "__main__":
    main()
