#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector < vector<int> > D(N + 1, vector<int>(N + 1));
	D[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		D[i][0] = D[i - 1][0];
		for (int j = 1; j < i; j++)
			D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
		D[i][i] = D[i - 1][i - 1];
	}
	cout << D[N][K] << endl;
	return 0;
}