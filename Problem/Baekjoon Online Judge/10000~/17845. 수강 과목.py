N, K = map(int, input().split())

dp = [0 for _ in range(N + 1)]
temp = [0 for _ in range(N + 1)]

for I, T in [map(int, input().split()) for _ in range(K)]:
    
    for i in range(T, N + 1):
        temp[i] = dp[i - T] + I

    for i in range(T, N + 1):
        dp[i] = max(dp[i], temp[i])

Max = 0
for i in range(N + 1):
    Max = max(Max, dp[i])

print(Max)
