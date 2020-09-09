N = int(input())
dp = [False, True, False, True]

for i in range(4, N+1):
    dp.append(not(dp[i-1] or dp[i-3] or dp[i-4]))

print("CY" if dp[N] else "SK")