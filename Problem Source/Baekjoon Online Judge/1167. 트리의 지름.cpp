#include<cstdio>
#include<vector>
using namespace std;

struct Z{
    int node, distance;
};
long long Max;
vector < bool > visited;
vector < vector<Z> > Edge;
int V, node, link, dis, start;

void dfs(int x, long long sum){
    int sz = Edge[x].size();
    visited[x] = true;
    for(int i=0;i<sz;i++){
        if(!visited[Edge[x][i].node]){
            dfs(Edge[x][i].node, sum + Edge[x][i].distance);
        }
    }
    if(Max < sum){
        Max = sum; start = x;
    }
}

int main(){
    scanf("%d",&V);
    Edge.resize(V+1);
    for(int i=0;i<V;i++){
        scanf("%d",&node);
        while(true){
            scanf("%d",&link);
            if(link == -1) break;
            scanf("%d",&dis);
            Edge[node].push_back(Z{link, dis});
        }
    }
    visited.resize(V+1, false);
    Max = 0; dfs(1, 0);
    visited.clear();
    visited.resize(V+1, false);
    Max = 0; dfs(start, 0);
    printf("%lld",Max);
    return 0;
}