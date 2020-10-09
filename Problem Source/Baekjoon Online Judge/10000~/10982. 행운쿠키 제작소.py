import sys

MAX = 1000*100
for _ in range(int(sys.stdin.readline())):

    n = int(sys.stdin.readline())
    A, B = [], []
    for _ in range(n):
        a, b = map(int, sys.stdin.readline().split())
        A.append(a)
        B.append(b)

    s = sum(A)
    dp = [[MAX for _ in range(s + 1)] for _ in range(2)]

    idx = 0
    dp[idx][s] = 0
    for x in range(n):
        idx = (idx + 1)%2
        dp[idx] = [MAX for _ in range(s + 1)]
        
        pre = (idx + 1)%2
        for c in range(s + 1):
            if dp[pre][c] != MAX:
                dp[idx][c] = dp[pre][c]
                dp[idx][c - A[x]] = min(dp[idx][c - A[x]], dp[pre][c] + B[x])
    
    Min = s
    for c in range(s+1):
        Min = min(Min, max(c, dp[idx][c]))
    print(Min)
