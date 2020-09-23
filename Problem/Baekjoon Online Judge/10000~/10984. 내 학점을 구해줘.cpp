#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int CC = 0;
        double GG = 0;
        for (int i = 0; i < N; i++) {
            int C;
            double G;
            cin >> C >> G;
            CC += C; GG += (C * G);
        }
        cout.precision(1);
        cout.setf(ios::fixed);
        cout << CC << " " << GG / CC << endl;
    }
    return 0;
}