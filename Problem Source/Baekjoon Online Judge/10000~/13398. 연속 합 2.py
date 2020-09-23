n = int(input())
lst = [-1001] + [*map(int, input().split())]

dp = [[0 for _ in range(n+1)] for _ in range(2)]

for i in range(1, n+1):
    dp[0][i] = max(dp[0][i-1]+lst[i], 0)
    dp[1][i] = max(dp[1][i-1] + lst[i], dp[0][i-1], 0)

Max = max(max(dp))
print(Max if Max > 0 else max(lst))