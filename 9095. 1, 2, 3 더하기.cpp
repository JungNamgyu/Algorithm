#include<iostream>
using namespace std;

int main() {
	int t, n, D[11];
	cin >> t;
	while (t--) {
		cin >> n;
		D[0] = 0, D[1] = 1, D[2] = 2, D[3] = 4;
		for (int i = 4; i <= n; i++) D[i] = D[i - 1] + D[i - 2] + D[i - 3];
		cout << D[n] << endl;
	}
	return 0;
}