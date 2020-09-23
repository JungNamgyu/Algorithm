import sys

N, M = map(int, input().split())

DB = [sys.stdin.readline().rstrip() for _ in range(N)]

name_to_ix = { name:(i+1) for i,name in enumerate(DB) } 
ix_to_name = { (i+1):name for i,name in enumerate(DB) }

for problem in (sys.stdin.readline().rstrip() for _ in range(M)):
    try:
        print(name_to_ix[problem])
    except:
        print(ix_to_name[int(problem)])
