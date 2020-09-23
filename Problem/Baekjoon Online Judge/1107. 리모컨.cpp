#include<iostream>
#include<algorithm>
using namespace std;

bool button[10];
int N, M, channel = 100;

inline int abs(int x){ return (x>0?x:-x);}

int Check(int n){
    int cnt = 0;
    while(!button[n%10] && n) n/=10, cnt++;
    return (n ? 2e9 : cnt);
}

int main(){
    cin >> N >> M;
    for(int i=0, B;i<M;i++){
        cin >> B; button[B]=true;
    }

    int Min = 2e9;
    for(int range = 0; range < abs(N-100); range++){
        if(0 < N-range)
            Min = min(Min, range + Check(N-range));
        if(0 == N-range || 0 == N+range)
            Min = min(Min, range + (!button[0] ? 1 : (int)2e9));
        else
            Min = min(Min, range + Check(N+range));
    }
    Min = min(Min, abs(N-100));
    cout << Min;
    return 0;
}