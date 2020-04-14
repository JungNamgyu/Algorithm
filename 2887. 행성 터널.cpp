#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pll;
typedef struct distance{ int c, a, b; } DISTANCE;
typedef struct planet{ int x, y, z, inx; } PLANET;

int N;
vector<PLANET> pl;
vector<int> group;
vector<bool> visit;
vector<DISTANCE> dis;

bool cmp_x(PLANET a, PLANET b) { return a.x < b.x; };
bool cmp_y(PLANET a, PLANET b) { return a.y < b.y; };
bool cmp_z(PLANET a, PLANET b) { return a.z < b.z; };
bool cmp(DISTANCE a, DISTANCE b){ return a.c < b.c; };

int Find(int x)
{
    return (group[x] == x ? x : group[x] = Find(group[x]));
}

bool Union(int a, int b)
{
    int pa = Find(a), pb = Find(b);
    group[pa] = pb;
    return (pa == pb ? false : true);
}

int main()
{
    scanf("%d", &N);

    pl.resize(N);
    group.resize(N);
    visit.resize(N, false);
    for (int i = 0; i < N; i++)
    {
        group[i] = pl[i].inx = i;
        scanf("%d%d%d", &pl[i].x, &pl[i].y, &pl[i].z);
    }
    
    sort(pl.begin(), pl.end(), cmp_x);
    for(int i=1;i<N;i++)
        dis.push_back(DISTANCE{pl[i].x - pl[i-1].x, pl[i].inx, pl[i-1].inx});
    sort(pl.begin(), pl.end(), cmp_y);
    for(int i=1;i<N;i++)
        dis.push_back(DISTANCE{pl[i].y - pl[i-1].y, pl[i].inx, pl[i-1].inx});
    sort(pl.begin(), pl.end(), cmp_z);
    for(int i=1;i<N;i++)
        dis.push_back(DISTANCE{pl[i].z - pl[i-1].z, pl[i].inx, pl[i-1].inx});
    
    sort(dis.begin(), dis.end(), cmp);
    int sz = dis.size(), sum = 0;
    for(int i=0;i<sz;i++){
        if(Union(dis[i].a, dis[i].b)){
            sum += dis[i].c;
        }
    }
    printf("%d", sum);

    return 0;
}