#include<iostream>
using namespace std;

int main() {
	long long Ans = 0, N, D[81] = { 0, 1, };

	cin >> N;
	for (int i = 2; i <= N; i++)
		D[i] = D[i - 1] + D[i - 2];
	cout << D[N] * 4 + D[N - 1] * 2;

	return 0;
}