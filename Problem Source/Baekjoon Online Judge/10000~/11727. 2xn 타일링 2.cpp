#include<iostream>
using namespace std;

int main() {
	int n, D[1001];
	cin >> n;
	D[1] = 1, D[2] = 3;
	for (int i = 3; i <= n; i++) D[i] = (D[i - 1] + D[i - 2] * 2) % 10007;
	cout << D[n];
	return 0;
}