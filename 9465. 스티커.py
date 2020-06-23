T = int(input())

for _ in range(T):
    n = int(input())
    S = [[*map(int, input().split())] for _ in range(2)]
    
    D = [[0 for _ in range(n)] for i in range(2)]

    D[0][0], D[1][0] = S[0][0], S[1][0]
    D[0][1], D[1][1] = D[1][0] + S[0][1], D[0][0] + S[1][1]
    
    for i in range(2, n):
        for j in range(2):
            D[j][i] = S[j][i] + max(D[1-j][i-2], D[1-j][i-1])

    print(max(D[0][n-1] + D[1][n-1]))
