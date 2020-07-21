N, K = map(int, input().split())

for i in range(N):
    if bin(N + i).count('1') <= K: break

print(i)
