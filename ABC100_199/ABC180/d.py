X, Y, A, B = map(int, input().split())
ans = 0
while(X < Y):
    if(X * (A - 1) > B):
        ans += (Y - X) // B
        if((Y - X) % B == 0):
            ans -= 1
        break
    else:
        X *= A
    if(X >= Y): break
    ans += 1
print(ans)
