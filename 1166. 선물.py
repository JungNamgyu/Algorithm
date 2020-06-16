N, L, W, H = map(int, input().split())

l, r = 0, min(L, W, H)
for i in range(10000):
    m = (l+r)/2
    if int(L/m) * int(W/m) * int(H/m) >= N:
        l = m
    else:
        r = m

print(m)
