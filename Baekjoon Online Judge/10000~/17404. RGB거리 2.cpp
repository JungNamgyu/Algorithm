#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, Min = 2e9;
vector < vector<int> > arr, D;

int main() {
	int i, j;
	cin >> N;
	arr.resize(N, vector<int>(3));
	for (i = 0; i < N; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	D.resize(N, vector<int>(3, 0));
	for (i = 0; i < 3; i++) {
		D[0][0] = arr[0][0]; 
		D[0][1] = arr[0][1];
		D[0][2] = arr[0][2];
		for (j = 1, D[0][i] = 2e9; j < N; j++) {
			D[j][0] = min(D[j - 1][1], D[j - 1][2]) + arr[j][0];
			D[j][1] = min(D[j - 1][0], D[j - 1][2]) + arr[j][1];
			D[j][2] = min(D[j - 1][0], D[j - 1][1]) + arr[j][2];
		}
		Min = min(Min, D[N - 1][i]);
	}
	cout << Min;
	return 0;
}