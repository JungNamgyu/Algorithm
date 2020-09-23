#include<iostream>
using namespace std;

int Test(int A, int B, int C, int N){
    for(int i=0;A*i<=N;i++){ for(int j=0;B*j<=N;j++){ for(int k=0;C*k<=N;k++){
        if(A*i + B*j + C*k == N)
            return 1;
    }}}
    return 0;
}
int main(){
    int A, B, C, N;
    cin >> A >> B >> C >> N;
    cout << Test(A,B,C,N);
    return 0;
}