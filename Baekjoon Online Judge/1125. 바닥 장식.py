#%% divide
def division(st, fi):
    sect = []
    
    if st % 5:
        sect.append(st)
        st = st + (5 - (st%5))
        
    sect = sect + [*range(st, fi, 5)] + [fi]
    
    return sect
#%% section prefix sum
def prefix(sect):
    S = [[0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0]]

    for i in range(len(sect) - 1):
        st, fi = sect[i], sect[i+1]
        S[(st // 5) % 2][fi - st] += 1
        
    return S
#%% program
from math import ceil

x1, y1, x2, y2 = map(int, input().split())

x = prefix(division(x1, x2))
y = prefix(division(y1, y2))

wood = [0, 0, 0, 0, 0, 0]
for i in range(1, 6):
    for j in range(1, 6):
        for t in [0, 1]:
            wood[i] += x[t][i] * (j*y[t][j]) #가로
            wood[j] += (i*x[t][i]) * y[1-t][j] #세로

answer = wood[5] + wood[4] + wood[3]

wood[1] -= wood[4]
wood[2] -= wood[3]

if wood[2] > 0:
    answer += ceil(wood[2]/2)
    wood[1] -= (ceil(wood[2]/2) + ((wood[2]%2)*2))
else:
    wood[1] -= (-wood[2])*2
    
if wood[1] > 0:
    answer = answer + (ceil(wood[1]/5))
    
print(answer)