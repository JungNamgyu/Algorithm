N, M, K = map(int, input().split())

dp = [[0 for _ in range(K + 1)] for _ in range(M + 1)]
temp = [[0 for _ in range(K + 1)] for _ in range(M + 1)]

for cheeze, potato in [map(int, input().split()) for _ in range(N)]:
    
    for i in range(cheeze, M + 1):
        for j in range(potato, K + 1):
            temp[i][j] = dp[i - cheeze][j - potato] + 1

    for i in range(cheeze, M + 1):
        for j in range(potato, K + 1):
            dp[i][j] = max(dp[i][j], temp[i][j])

Max = 0
for i in range(M + 1):
    for j in range(K + 1):
       Max = max(Max, dp[i][j])

print(Max)
