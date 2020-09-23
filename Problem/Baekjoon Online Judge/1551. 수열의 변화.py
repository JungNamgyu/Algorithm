N, K = map(int, input().split())
A = [*map(int, input().split(','))]

for i in range(K):
    B = []
    for j in range(len(A)-1):
        B.append(int(A[j+1]-A[j]))
    A = B

print(','.join(map(str, A)))
