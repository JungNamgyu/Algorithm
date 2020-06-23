from math import ceil

N = int(input())
A = [*map(int, input().split())]
B, C = map(int, input().split())

R = [ (i - B if (i - B > 0) else 0) for i in A]

O = [ ceil(i/C) for i in R ]

print(sum(O) + N)
