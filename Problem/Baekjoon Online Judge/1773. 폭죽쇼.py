N, C = map(int, input().split())

Firecreacker = [False for _ in range(C+1)]

for i in [int(input()) for _ in range(N)]:
    if not Firecreacker[i]:
        for j in range(i, C+1, i):
            Firecreacker[j] = True

cnt = 0
for i in range(C+1):
    if Firecreacker[i]:
        cnt+=1

print(cnt)