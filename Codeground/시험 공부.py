import sys

inf = sys.stdin 

T = inf.readline();

for t in range(0, int(T)):
    
    Answer=0;
    
    #############################################################################################
    
    N, K = map(int, input().split())

    S = [ *map(int, input().split()) ]
    S.sort(reverse=True)
    
    for inx in range(K):
        Answer = Answer + S[inx]
            
    #############################################################################################
	
    print('Case #%d' %(int(t)+1))    
    print(Answer)
    
inf.close()
