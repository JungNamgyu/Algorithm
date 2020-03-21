#include <cstdio>
#include <vector>
using namespace std;

vector<int> P;
vector<bool> Check;

int Find(int x)
{
    if (P[x] == x)
        return x;
    return P[x] = Find(P[x]);
}

void Union(int a, int b)
{
    int pa = Find(a), pb = Find(b);
    if (pa != pb)
        P[pb] = pa;
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);

    P.resize(N + 1);
    for (int i = 1; i <= N; i++)
        P[i] = i;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        Union(u, v);
    }

    int cnt = 0;
    Check.resize(N + 1, false);
    for (int i = 1; i <= N; i++)
    {
        int parent = Find(i);
        if (!Check[parent])
        {
            cnt++;
            Check[parent] = true;
        }
    }
    printf("%d", cnt);
    return 0;
}