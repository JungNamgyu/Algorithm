#include <cstdio>
#include <vector>
using namespace std;

vector<bool> V;
vector<int> L, R, ANS;

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    L.resize(N + 1, 0);
    R.resize(N + 1, 0);
    V.resize(N + 1, false);
    for (int i = 0; i < M; i++)
    {
        int X, Y;
        scanf("%d%d", &X, &Y);
        R[X]++;
        L[Y]++;
    }
    for (int i = 1; i <= N; i++)
    {
        if (1 <= i + R[i] - L[i] && i + R[i] - L[i] <= N)
        {
            if (!V[i + R[i] - L[i]])
            {
                V[i + R[i] - L[i]] = true;
                ANS.push_back(i + R[i] - L[i]);
            }
        }
    }
    int sz = ANS.size();
    if (sz < N)
        printf("-1");
    else
    {
        for (int i = 0; i < sz; i++)
            printf("%d ", ANS[i]);
    }
    return 0;
}