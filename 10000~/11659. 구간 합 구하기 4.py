import sys

N, M = map(int, sys.stdin.readline().split())

Num = [ 0, *map(int, sys.stdin.readline().split())]

Sum = [ 0 ]
for i in range(1, N+1):
    Sum.append(Sum[i-1] + Num[i])

for _ in range(M):
    i, j = map(int, sys.stdin.readline().split())
    print(Sum[j] - Sum[i-1])
