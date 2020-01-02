#include<iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N,M;
        cin >> N >> M;
        cout << (N>=12 && M>=4 ? 11*M+4 : -1) << endl;
    }
    return 0;
}