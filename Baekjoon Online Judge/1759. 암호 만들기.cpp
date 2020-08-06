#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> alpha;
char s[20], data[] = {'a', 'e', 'i', 'o', 'u'};

int check(int x)
{
    bool ch = false;
    for (int i = 0; i < 5; i++)
    {
        if (data[i] == s[x])
            ch = true;
    }
    return (ch ? 1 : 0);
}

void dfs(int x, int len)
{
    if (len == L)
    {
        int cnt = 0;
        for (int i = 0; i < len; i++)
            cnt += check(i);
        if (cnt >= 1 && len - cnt >= 2)
            printf("%s\n", s);
    }
    else
    {
        for (int i = x; i < C; i++)
        {
            s[len] = alpha[i];
            dfs(i + 1, len + 1);
            s[len] = NULL;
        }
    }
}

int main()
{
    scanf("%d%d", &L, &C);
    alpha.resize(C);
    for (int i = 0; i < C; i++)
        scanf(" %c", &alpha[i]);
    sort(alpha.begin(), alpha.end());
    dfs(0, 0);
    return 0;
}