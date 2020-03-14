#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct Z{ int y, x; };
inline int dis(Z a, Z b){ return abs(a.y-b.y) + abs(a.x-b.x); }

int N, W, D[1001][1001];
Z Inx[1001], Path[1001][1001];

void One(int y, int x){
    Path[y][x].y = 0, Path[y][x].x = x;
    D[y][x] = D[0][x] + dis(Inx[y], Z{1,1});
    for(int k=1;k<y-1;k++){
        if(D[y][x] > D[k][x] + dis(Inx[k],Inx[y])){
            Path[y][x].y = k, Path[y][x].x = x;
            D[y][x] = D[k][x] + dis(Inx[k], Inx[y]);
        }
    }
}
void Two(int y, int x){
    Path[y][x].y = y, Path[y][x].x = 0;
    D[y][x] = D[y][0] + dis(Inx[x], Z{N,N});
    for(int k=1;k<x-1;k++){
        if(D[y][x] > D[y][k] + dis(Inx[k],Inx[x])){
            Path[y][x].y = y, Path[y][x].x = k;
            D[y][x] = min(D[y][x], D[y][k] + dis(Inx[k], Inx[x]));
        }
    }
}

int main(){
    cin >> N >> W;
    for(int i=1;i<=W;i++) cin >> Inx[i].y >> Inx[i].x;

    for(int i=0;i<=W;i++){
        for(int j=0;j<=W;j++){
            if(i > j){
                if(i-1==j)
                    One(i, j);
                else{
                    Path[i][j].y = i-1, Path[i][j].x = j;
                    D[i][j] = D[i-1][j] + dis(Inx[i-1], Inx[i]);
                }
            }
            if(i < j){
                if(i==j-1)
                    Two(i, j);
                else{
                    Path[i][j].y = i, Path[i][j].x = j-1;
                    D[i][j] = D[i][j-1] + dis(Inx[j-1], Inx[j]);
                }
            }
        }
    }
    
    Z Min{0, W};
    for(int i=0;i<W;i++){
        if(D[Min.y][Min.x] > D[i][W]) Min = Z{i,W};
        if(D[Min.y][Min.x] > D[W][i]) Min = Z{W,i};
    }
    cout << D[Min.y][Min.x] << endl;

    int Cache[1001];
    while(!(Min.y == 0 && Min.x == 0)){
        (Min.y > Min.x ? Cache[Min.y] = 1 : Cache[Min.x] = 2);
        Min = Path[Min.y][Min.x];
    }
    for(int i=1;i<=W;i++)
        cout << Cache[i] << endl;
    return 0;
}