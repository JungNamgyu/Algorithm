import random
import copy
import numpy as np

yy, xx = np.array([-1, 0, 1, 0]), np.array([ 0, 1, 0,-1])
#########################################################################
def init_path(path):
    
    for i in range(path.shape[0]):
        for j in range(path.shape[1]):
            path[i][j] = random.randint(0, 3)
    
    return path
#########################################################################
def crossroads(y, x, visit, flag):
    cnt = 0
    for j in range(4):
        next_y, next_x = y + yy[j], x + xx[j]
        if(next_y in range(20) and next_x in range(20)):
            if(maze[next_y][next_x] == 0 and visit[next_y][next_x] == 0):
                cnt += 1
    
    if cnt == 0:
        flag = True
        
    return (cnt > 1)
#########################################################################
def genetic_algorithm(path):
    
    flag = False # 막다른 길일 경우
    find = False # 출구 찾았을 경우
    Mutation = [[] for _ in range(path.shape[0])]
    score = np.zeros((path.shape[0]), dtype = 'i')
    index = np.zeros((path.shape[0]), dtype = 'i')
    # 적합도 평가
    for n in range(path.shape[0]):
        
        y, x = st_y, st_x
        visit = np.zeros((20,20), dtype = 'i')
        
        for i in range(path.shape[1]):
            
            if(crossroads(y, x, visit, flag)):
                Mutation[n].append(i)
                
            next_y, next_x = y + yy[path[n][i]], x + xx[path[n][i]]
            if(next_y in range(20) and next_x in range(20) and maze[next_y][next_x] == 0 and visit[next_y][next_x] == 0):
                y, x = next_y, next_x
                visit[y][x] = 1
                if(y == end_y and x == end_x):
                    print_path(path, st_y, st_x, n)
                    find = True
                
            else:
                index[n], score[n] = i, (0 if flag else (i + ((abs(st_y - y) + abs(st_x - x)) / 2)))
                break
    
    # 룰렛 휠 선택
    Roulette = []
    Probability = score / np.sum(score) * 100
    for n in range(path.shape[0]):
        for i in range(0, np.int(Probability[n])):
            Roulette.append(n)
    
    # 자손 번식
    child_path = np.empty((path.shape), dtype='i')
    for i in range(path.shape[0]):
        select = random.choice(Roulette)
        for j in range(path.shape[1]):
            child_path[i][j] = (path[select][j] if (j < index[select]) else random.randint(0, 3))
            if(j in Mutation[i]):
                if(1 == random.randint(1, 100)):
                    child_path[i][j] = random.randint(0,3)
    
    return child_path, find
#########################################################################
def print_path(path, y, x, inx = 0):
    
    print_path = copy.deepcopy(maze)
    
    for i in range(path.shape[1]):
        next_y, next_x = y + yy[path[inx][i]], x + xx[path[inx][i]]
        if(next_y in range(0, 20) and next_x in range(0, 20) and maze[next_y][next_x] == 0):
            y, x = next_y, next_x
            print_path[next_y][next_x] = 2
        else:
            if(next_y == end_y and next_x == end_x):
                print_path[next_y][next_x] = 2
            break
            
    for i in range(20):
        for j in range(20):
            if(print_path[i][j] == 2):
                print("☆", end='')
            else:
                print("■" if print_path[i][j] else "  ", end='')
        print()
#########################################################################
st_y, st_x = -1, 1
end_y, end_x = 19, 18

maze = np.array([[1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],
                 [1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,1],
                 [1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1],
                 [1,0,1,0,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1],
                 [1,0,1,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,1],
                 [1,0,1,0,0,1,0,0,0,1,1,1,1,0,1,1,1,1,0,1],
                 [1,0,1,0,1,1,1,1,0,1,0,0,1,0,1,0,0,1,0,1],
                 [1,0,1,0,0,0,0,1,0,1,1,0,1,0,1,0,1,1,0,1],
                 [1,0,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1],
                 [1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1],
                 [1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,1],
                 [1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1],
                 [1,0,1,0,1,0,0,0,0,1,0,0,1,0,1,1,1,1,0,1],
                 [1,0,1,0,1,0,1,0,1,1,0,1,1,0,1,0,0,1,0,1],
                 [1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,1,0,1],
                 [1,0,1,0,1,1,1,0,1,1,0,1,0,1,1,0,1,1,0,1],
                 [1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1],
                 [1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1],
                 [1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1],
                 [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1]])
#########################################################################
path = init_path(np.empty((10, 400), dtype='i')) # 북 : 0, 동 : 1, 남 : 2, 서 : 3
        
for i in range(10000):
    path, find = genetic_algorithm(path)
    if(i % 100 == 0):
        print_path(path, st_y, st_x, random.randint(0, 9))
        print("                                   {0}세대\n".format(i))
    if(find):
        print("            Find                   {0}세대\n".format(i))
        break
#########################################################################
