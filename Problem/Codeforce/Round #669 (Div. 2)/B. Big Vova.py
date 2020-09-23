def GCD(a, b):
    return (GCD(b, a%b) if a%b else b)

def swap(lst, i, j):
    (lst[i], lst[j]) = (lst[j], lst[i])
    
for _ in range(int(input())):
    n = int(input())
    a = [*map(int, input().split())]
    
    swap(a, 0, a.index(max(a)))
    
    gcd = a[0]
    for i in range(1, n):
        b = [0 for _ in range(i)]
        for j in range(i, n):
            b.append(GCD(gcd, a[j]))
        gcd = max(b)
        swap(a, i, b.index(gcd))
        
    print(' '.join(map(str, a)))