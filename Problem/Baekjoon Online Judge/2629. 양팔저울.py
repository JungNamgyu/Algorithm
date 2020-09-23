n = int(input())

dp = [0 for _ in range(30001)]
temp = [0 for _ in range(30001)]

dp[15000] = 1
for W in [*map(int, input().split())]:
    for put in [-1, 0, 1]: # -1:le, 0:no, 1:ri
        for x in range(30001):
            if W*put + x in range(30001):
               temp[W*put+x] += dp[x];
    for x in range(30001):
        dp[x] = temp[x];

m = int(input())

answer = []
for M in [*map(int, input().split())]:
    if M in range(15000):
        answer.append('Y' if dp[M+15000] else 'N')
    else:
        answer.append('N')
print(' '.join(answer))