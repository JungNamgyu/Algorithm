#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

vector<bool> visit;
vector<int> Dis, Max;
vector< vector<int> >Edge;
priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > Q;

int main(){
    int N, One, Two;
    scanf("%d%d%d",&N,&One,&Two);

    Edge.resize(N+1);
    Max.resize(N+1, 0);
    Dis.resize(N+1, 2e9);
    visit.resize(N+1, false);

    for(int i=1;i<N;i++){
        int s, e, v;
        scanf("%d%d%d",&s,&e,&v);
        Edge[s].push_back(e); Edge[s].push_back(v);
        Edge[e].push_back(s); Edge[e].push_back(v);
    }

    Q.push(make_pair(0, One));
    
    Dis[One] = 0;
    while(!Q.empty()){
        int X = Q.top().second; Q.pop();
        if(X == Two) break;
        visit[X] = true;
        int sz = Edge[X].size();
        for(int i=0;i<sz;i+=2){
            int room = Edge[X][i], dis = Edge[X][i+1];
            if(!visit[room]){
                Max[room] = max(Max[X], dis);
                Dis[room] = min(Dis[room], Dis[X]+dis);
                Q.push(make_pair(Dis[room], room));
            }
        }
    }

    printf("%d\n", Dis[Two] - Max[Two]);    
    return 0;
}