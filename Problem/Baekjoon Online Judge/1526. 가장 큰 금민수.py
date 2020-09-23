N = int(input())

for i in range(N, 3, -1):
    M = i
    while M%10==4 or M%10==7:
        M = int(M/10)
    if M==0:
        break

print(i)
