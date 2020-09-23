#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector < vector<int> > Dot;

int main(){
    int N;
    cin >> N;
    Dot.resize(N+1);

    for(int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        Dot[y].push_back(x);
    }
    int sum = 0;
    for(int i=1;i<=N;i++){
        sort(Dot[i].begin(), Dot[i].end());
        int Min = 2e9;
        for(int j=0;j<Dot[i].size();Min=2e9, j++){
            if(j-1 >= 0) Min = min(Min, Dot[i][j] - Dot[i][j-1]);
            if(j+1 < Dot[i].size()) Min = min(Min, Dot[i][j + 1] - Dot[i][j]);
            sum += Min;
        }
    }
    cout << sum;
    return 0;
}