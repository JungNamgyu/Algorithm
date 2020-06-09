result = [[i]+[0]*4 for i in range(1, 4)]

for _ in range(int(input())):
    vote = [*map(int, input().split())]
    for i in range(3):
        result[i][vote[i]] += 1

for i in range(3):
    result[i][4] = sum(j * result[i][j] for j in range(1,4))

for i in range(1, 5):
    result.sort(key = lambda x: x[i], reverse=True)

print(0 if result[0][1:] == result[1][1:] else result[0][0], result[0][4])
