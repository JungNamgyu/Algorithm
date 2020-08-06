import sys

inf = sys.stdin 

T = inf.readline();

for t in range(0, int(T)):
    
    Answer=0;
    
    ###################################################################################
    
    N = input()

    for inx in map(int, input().split()):
        Answer = Answer ^ inx
            
    ###################################################################################
	
    print('Case #%d' %(int(t)+1))    
    print(Answer)
    
inf.close()
