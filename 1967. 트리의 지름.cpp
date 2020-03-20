#include<cstdio>
#include<vector>
using namespace std;

struct Z{
    int node, distance;
};
vector < bool > visited;
vector < vector<Z> > Edge;
int Max, V, start, s, e, v;

void dfs(int x, int sum){
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
    for(int i=1;i<V;i++){
        scanf("%d %d %d",&s, &e, &v);
        Edge[s].push_back(Z{e, v});
        Edge[e].push_back(Z{s, v});
    }
    visited.resize(V+1, false);
    Max = 0; dfs(1, 0);
    visited.clear();
    visited.resize(V+1, false);
    Max = 0; dfs(start, 0);
    printf("%d",Max);
    return 0;
}