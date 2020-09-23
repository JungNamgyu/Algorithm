#include<iostream>
using namespace std;

int main() {
	int K, D[46][2];

	cin >> K;
	D[0][0] = 1, D[0][1] = 0;
	for (int i = 1; i <= K; i++) {
		D[i][0] = D[i - 1][1];
		D[i][1] = D[i - 1][0] + D[i - 1][1];
	}
	cout << D[K][0] << " " << D[K][1];

	return 0;
}