#include<iostream>
using namespace std;

int T, N;
long long D[101] = { 0, 1, 1, 1, 2 };

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 5; i <= N; i++)
			D[i] = D[i - 1] + D[i - 5];
		cout << D[N] << endl;
	}
	return 0;
}