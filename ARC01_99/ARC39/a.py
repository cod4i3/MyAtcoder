A, B = map(int, input().split())
print(max((A % 100 + 900) - B, A - (B % 100 + 100),
          ((A % 10) + 90 + (A // 100) * 100) - B,
          A - ((B % 10) + (B // 100) * 100),
          (A - A % 10 + 9) - B,
          A - (B - B % 10)))