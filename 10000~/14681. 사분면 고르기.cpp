#include<iostream>
using namespace std;

int main(){
    int x,y;
    cin >> x >> y;
    if(x>0)
        cout << (y>0 ? 1 : 4) << endl;
    else
        cout << (y>0 ? 2 : 3) << endl;
    return 0;
}