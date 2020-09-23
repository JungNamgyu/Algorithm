N = int(input())

Maze = [ *map(int, input().split()) ]
Count = [ *(1001 for _ in range(N - 1)), 0 ]

for i in reversed(range(N - 1)):
    if Maze[i] :
        Count[i] = min(Count[i+1:(i+Maze[i]+1)]) + 1

print(Count[0] if Count[0] <= 1000 else -1)
