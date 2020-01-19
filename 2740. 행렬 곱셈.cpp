#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, M, K;

	cin >> N >> M;
	vector < vector <int> > A(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	
	cin >> M >> K;
	vector < vector <int> > B(M, vector<int>(K));
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> B[i][j];

	vector < vector <int> > AB(N, vector<int>(K, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < K; j++)
			for (int u = 0; u < M; u++)
				AB[i][j] += A[i][u] * B[u][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++)
			cout << AB[i][j] << " ";
		cout << endl;
	}
	return 0;
}