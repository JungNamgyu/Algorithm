#include <iostream>
using namespace std;

int main() {
    int C, K, x, M = 1;
    cin >> C >> K;
    for (int i = 0; i < K; i++) M *= 10;
    x = (C + (5 * M / 10));
    x = (double)x / M;
    x = x * M;
    cout << x;
    return 0;
}