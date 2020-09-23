#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int a, A[5] = {0};
        scanf("%d", &a);
        for (int j = 0, n; j < a; j++)
        {
            scanf("%d", &n);
            A[n]++;
        }
        int b, B[5] = {0};
        scanf("%d", &b);
        for (int j = 0, n; j < b; j++)
        {
            scanf("%d", &n);
            B[n]++;
        }
        if (A[4] == B[4])
        {
            if (A[3] == B[3])
            {
                if (A[2] == B[2])
                {
                    if (A[1] == B[1])
                        printf("D\n");
                    else
                        printf("%c\n", (A[1] > B[1] ? 'A' : 'B'));
                }
                else
                    printf("%c\n", (A[2] > B[2] ? 'A' : 'B'));
            }
            else
                printf("%c\n", (A[3] > B[3] ? 'A' : 'B'));
        }
        else
            printf("%c\n", (A[4] > B[4] ? 'A' : 'B'));
    }
    return 0;
}