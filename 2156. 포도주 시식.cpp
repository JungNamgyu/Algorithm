#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector <int> arr(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	
	vector < vector<int> > D(3, vector<int>(N + 1));
	for (int i = 1; i <= N; i++) {
		D[2][i] = D[1][i - 1] + arr[i];
		D[1][i] = D[0][i - 1] + arr[i];
		D[0][i] = max(D[0][i-1],max(D[1][i-1],D[2][i - 1]));
	}
	cout << max(D[0][N], max(D[1][N], D[2][N]));
	return 0;
}