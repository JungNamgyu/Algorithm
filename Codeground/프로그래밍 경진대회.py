import sys

inf = sys.stdin 

T = inf.readline();

for t in range(0, int(T)):
    
    Answer=0;
    
    #############################################################################################

    N = int(input())
    P = sorted([ int(input()) for _ in range(N) ])

    M = [ (P[i] + (N - i)) for i in range(N) ]
    Max = max(M)
    
    for score in P:
        if (score + N >= Max):
            Answer = Answer + 1
    #############################################################################################
	
    print('Case #%d' %(int(t)+1))    
    print(Answer)
    
inf.close()
