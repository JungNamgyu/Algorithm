#include<iostream>
using namespace std;

int main() {
	int n, k, pascal[31][31] = { 1, };

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
	cout << pascal[n][k];

	return 0;
}