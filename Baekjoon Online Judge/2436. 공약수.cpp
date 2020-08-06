#include <cstdio>

bool GCD(int x, int y)
{
    if (x % y == 0)
        return (y == 1 ? true : false);
    return GCD(y, x % y);
}

int main()
{
    int N, a, b, ans1, ans2;

    scanf("%d%d", &a, &b);
    
    N = b / a;
    for (int i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
            if (GCD(N/i, i))
                ans1 = i , ans2 = N/i;
    }

    printf("%d %d", ans1 * a, ans2 * a);

    return 0;
}