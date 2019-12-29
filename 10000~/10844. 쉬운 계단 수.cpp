#include<iostream>
#include<vector>
using namespace std;
#define M 1000000000

int main() {
	int N;
	cin >> N;
	vector <vector<int>> D(10, vector<int>(N + 1, 0));
	for (int i = 1; i <= 9; i++)
		D[i][1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			switch (j) {
			case 0: D[j][i] = D[j + 1][i - 1]; break;
			case 9: D[j][i] = D[j - 1][i - 1]; break;
			default:D[j][i] = (D[j - 1][i - 1] + D[j + 1][i - 1]) % M;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i <= 9; i++)
		sum = (sum + D[i][N]) % M;
	cout << sum;
	return 0;
}