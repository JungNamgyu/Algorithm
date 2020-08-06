#include <iostream>
using namespace std;

int main()
{
    int L, P;
    cin >> L >> P;
    for (int i = 0; i < 5; i++)
    {
        int Attend;
        cin >> Attend;
        cout << Attend - L*P << " ";
    }
    return 0;
}