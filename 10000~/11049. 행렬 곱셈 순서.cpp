#include<iostream>
#include<vector>
using namespace std;

struct Matrix{
    int r, c;
};

int N;
vector < Matrix > M;
vector < vector<long long> > D;

int main(){
    cin >> N;
    M.resize(N);
    D.resize(N, vector<long long>(N, 0) );
    for(int i=0;i<N;i++) cin >> M[i].r >> M[i].c;
    for(int en=0;en<N;en++){
        for(int st=en-1;st>=0;st--){
            D[st][en] = 2e9;
            for(int k=1;k<=en-st;k++)
                D[st][en] = min(D[st][en], D[st][en-k] + D[en-k+1][en] + M[st].r * M[en-k].c * M[en].c);
        }
    }
    cout << D[0][N-1] << endl;
    return 0;
}