#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct app
{
    int m, c;
    bool operator<(const app &a)
    {
        if (this->c == a.c)
            return this->m > a.m;
        return this->c < a.c;
    }
};
vector<app> App;
vector<int> Cache;

int main()
{
    int N, M, sum = 0;
    cin >> N >> M;

    App.resize(N);
    for (int i = 0; i < N; i++)
        cin >> App[i].m;
    for (int i = 0; i < N; i++)
    {
        cin >> App[i].c;
        sum += App[i].c;
    }
    Cache.resize(sum + 1);
    sort(App.begin(), App.end());
    for (int i = 0; i < N; i++)
    {
        for (int j = sum; j >= App[i].c; j--)
        {
            if (Cache[j - App[i].c] > 0)
                Cache[j] = max(Cache[j], Cache[j - App[i].c] + App[i].m);
        }
        Cache[App[i].c] = max(Cache[App[i].c], App[i].m);
    }
    int Min = 2e9;
    for (int i = sum; i >= 0; i--)
        if(M <= Cache[i]) Min = i;
    cout << Min << endl;
    return 0;
}