#include<iostream>
#include<algorithm>
using namespace std;

int D[50001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int Min = 2e9;
		for (int j = 1; j * j <= i; j++) {
			Min = min(Min, D[i - (j * j)]);
		}
		D[i] = Min + 1;
	}
	cout << D[n];
	return 0;
}