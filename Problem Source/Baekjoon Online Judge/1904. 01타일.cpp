#include<iostream>
using namespace std;

const int M = 15746;
int N, D[1000001] = { 0, 1, 2 };

int main() {
	cin >> N;
	for (int i = 3; i <= N; i++)
		D[i] = (D[i - 1] + D[i - 2]) % M;
	cout << D[N];
	return 0;
}