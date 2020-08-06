#include<iostream>
#include<vector>
using namespace std;

int T, K, File[500], Cache[500][500][2];

int Merge_FILE(){
    for(int i=0;i<K;i++){
        Cache[i][i][0] = File[i];
        for(int j=i-1;j>=0;j--){
            Cache[j][i][1] = 2e9;
            for(int k=1;k<=i-j;k++){
                int Ly = j, Lx = i-k, Ry = i-k+1, Rx = i;
                if(Cache[j][i][1] > Cache[Ly][Lx][0] + Cache[Ry][Rx][0] + Cache[Ly][Lx][1] + Cache[Ry][Rx][1]){
                    Cache[j][i][0] = Cache[Ly][Lx][0] + Cache[Ry][Rx][0];
                    Cache[j][i][1] = Cache[Ly][Lx][0] + Cache[Ry][Rx][0] + Cache[Ly][Lx][1] + Cache[Ry][Rx][1];
                } 
            }
        }
    }
    return Cache[0][K-1][1];
}

int main(){
    cin >> T;
    while(T--){
        cin >> K; 
        for(int i=0;i<K;i++) cin >> File[i];
        cout << Merge_FILE() << endl;
    }
    return 0;
}