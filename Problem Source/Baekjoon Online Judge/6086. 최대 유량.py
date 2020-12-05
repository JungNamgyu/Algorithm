from string import ascii_letters as alpha

cap = {i: {j: 0 for j in alpha} for i in alpha}
flow = {i: {j: 0 for j in alpha} for i in alpha}

def path(x, x_min):
    check[x] = True
    if x == 'Z': return x_min, False

    for i in alpha:
        if not check[i] and cap[x][i] - flow[x][i] > 0:
            F, visit = path(i, min(x_min, cap[x][i] - flow[x][i]))
            if not visit:
                flow[x][i], flow[i][x] = flow[x][i] + F, flow[i][x] - F
                return F, visit

    return 2e9, True

if __name__ == '__main__':
    for _ in range(int(input())):
        a, b, c = input().split()
        cap[a][b], cap[b][a] = cap[a][b] + int(c), cap[b][a] + int(c)

    while True:
        check = {i: False for i in alpha}

        F, visit = path('A', 2e9)
        if visit: break

    sum = 0
    for i in alpha:
        sum += flow[i]['Z']
    print(sum)