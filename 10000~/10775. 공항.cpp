#include <cstdio>
#include <vector>
using namespace std;

int G, P, g;
vector<int> Gate;

int FIND(int x)
{
    if (Gate[x] == x)
        return x;
    return Gate[x] = FIND(Gate[x]);
}

void UNION(int g_, int g)
{
    Gate[g] = FIND(g_);
}

int main()
{
    int i;
    scanf("%d%d", &G, &P);
    for (i = 0; i <= G; i++)
        Gate.push_back(i);
    for (i = 0; i < P; i++)
    {
        scanf("%d", &g);
        int p = FIND(g);
        if (p == 0)
        {
            printf("%d", i);
            break;
        }
        UNION(p - 1, p);
    }
    if (i == P)
        printf("%d", i);
    return 0;
}