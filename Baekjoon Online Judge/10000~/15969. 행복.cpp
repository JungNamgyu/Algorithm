#include<iostream>
using namespace std;

int main(){
    int n, Max = 0, Min = 1000;
    cin >> n;
    for(int i=0;i<n;i++){
        int score;
        cin >> score;
        Max = max(Max, score);
        Min = min(Min, score);
    }
    cout << Max - Min;
    return 0;
}