#include<iostream>
using namespace std;

int main() {
	int N, Y = 0, M = 0;
	cin >> N;
	while (N--) {
		int x;
		cin >> x;
		Y += ((x / 30) + 1) * 10;
		M += ((x / 60) + 1) * 15;
	}
	if (Y == M)
		cout << "Y M " << Y;
	if (Y < M)
		cout << "Y " << Y;
	if (M < Y)
		cout << "M " << M;
	return 0;
}