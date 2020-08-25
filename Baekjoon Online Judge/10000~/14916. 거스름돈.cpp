#include<iostream>
#include<algorithm>
using namespace std;

int n, D[100001];

int main() {

	cin >> n;

	D[2] = 1, D[4] = 2, D[5] = 1;
	for (int i = 6; i <= n; i++) {
		D[i] = 100001;
		if (D[i - 2])
			D[i] = min(D[i], D[i - 2] + 1);
		if (D[i - 5])
			D[i] = min(D[i], D[i - 5] + 1);
		if (D[i] == 100001)
			D[i] = 0;
	}
	cout << (D[n] == 0 ? -1 : D[n]);

	return 0;
}