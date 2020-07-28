import sys

N, M = map(int, sys.stdin.readline().split())

Num = [[*map(int, sys.stdin.readline().split())] for _ in range(N)]

Sum = [[ 0 for _ in range(N) ] for _ in range(N)]
for y in range(N):
    for x in range(N):
        Sum[y][x] = Num[y][x]
        if(0 < y and 0 < x):
            Sum[y][x] -= Sum[y - 1][x - 1]
        if(0 < y):
            Sum[y][x] += Sum[y - 1][x]
        if(0 < x):
            Sum[y][x] += Sum[y][x - 1]

for _ in range(M):
    y1, x1, y2, x2 = map(int, sys.stdin.readline().split())

    Answer = Sum[y2 - 1][x2 - 1]
    if(1 < y1 and 1 < x1):
        Answer += Sum[y1 - 2][x1 - 2]
    if(1 < y1):
        Answer -= Sum[y1 - 2][x2 - 1]
    if(1 < x1):
        Answer -= Sum[y2 - 1][x1 - 2]
        
    print(Answer)
