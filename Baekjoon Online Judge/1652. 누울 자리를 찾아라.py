def Lie(room, cnt=0):
    for i in room:
        for lie in i.split("X"):
            if(len(lie)>=2):
                cnt+=1
    return cnt

N = int(input())
A = [input() for _ in range(N)]
T_A = [ ''.join(i) for i in list(zip(*A))]

row, col = Lie(A), Lie(T_A)

print(row, col)
