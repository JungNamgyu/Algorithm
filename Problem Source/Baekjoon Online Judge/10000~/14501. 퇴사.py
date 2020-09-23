N = int(input())
C = [[0, 0]] + [[*map(int, input().split())] for _ in range(N)]

cache = [0 for _ in range(N+2)]
for i in range(1, N+1):
    cache[i] = max(cache[i], cache[i-1])
    if i + C[i][0] <= N+1:
        cache[i+C[i][0]] = max(cache[i+C[i][0]], cache[i] + C[i][1])

print(max(cache[N], cache[N + 1]))