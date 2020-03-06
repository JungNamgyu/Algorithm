#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, W, H, D;
    cin >> N >> W >> H;
    D = sqrt(pow(W, 2) + pow(H, 2));
    while (N--) {
        int n;
        cin >> n;
        if (n <= W || n <= H || n <= D)
            cout << "DA" << endl;
        else
            cout << "NE" << endl;
    }
    return 0;
}