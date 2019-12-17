#include<iostream>
#include<algorithm>
using namespace std;

int n, D[1000001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (!D[i]) {
			for (int j = i, N, s; j <= n; j = s, D[s] = N) {
				s = N = j;
				while (j) {
					s += j % 10;
					j /= 10;
				}
				if (D[s]) {
					D[s] = min(D[s], N);
					break;
				}
			}
		}
	}
	cout << D[n];
	return 0;
}