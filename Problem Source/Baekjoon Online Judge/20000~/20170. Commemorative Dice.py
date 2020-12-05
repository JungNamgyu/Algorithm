def gcd(a, b):
    return gcd(b, a%b) if a%b else b

A = [*map(int, input().split())]
B = [*map(int, input().split())]

X = sum(sum(x) for x in [[*map(lambda b: 1 if a>b else 0, B)] for a in A])
GCD = gcd(36, X)

print('{0}/{1}'.format(int(X/GCD), int(36/GCD)))