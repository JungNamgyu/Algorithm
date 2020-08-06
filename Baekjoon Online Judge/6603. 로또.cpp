#include <cstdio>
#include <vector>
using namespace std;

int k;
char Lotto[7];
vector<int> Data;

void DFS(int x, int len)
{
    if (len == 6)
    {
        for (int i = 0; i < len; i++)
            printf("%d ", Lotto[i]);
        printf("\n");
    }
    else
    {
        for (int i = x; i < k; i++)
        {
            Lotto[len] = Data[i];
            DFS(i + 1, len + 1);
        }
    }
}

int main()
{
    while (true)
    {
        scanf("%d", &k);
        if (k == 0)
            break;
        Data.resize(k);
        for (int i = 0; i < k; i++)
            scanf("%d", &Data[i]);
        DFS(0, 0);
        printf("\n");
    }
    return 0;
}