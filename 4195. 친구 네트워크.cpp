#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> Parents;
vector< vector<int> > Tree;

void Setting(int x)
{
    int sz = Tree[x].size();
    for (int i = 0; i < sz; i++)
    {
        if (Parents[Tree[x][i]] > 0)
            continue;
        Parents[Tree[x][i]] = x;
        Setting(Tree[x][i]);
    }
}
int main()
{
    scanf("%d", &N);
    Tree.resize(N + 1);
    Parents.resize(N + 1, 0);
    for (int i = 1; i < N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }
    Parents[1] = 1;
    Setting(1);
    for (int i = 2; i <= N; i++)
        printf("%d\n", Parents[i]);
    return 0;
}